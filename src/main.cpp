/**
 * An example Dreamcast program.
 */

#include "registers.h"

#define VRAM_BASE       0xA5000000
#define VRAM64_BASE     0xA4000000
#define VRAM_BANK1_BASE 0x00000000
#define VRAM_BANK1_END  0x003FFFFC
#define VRAM_BANK2_BASE 0x00400000
#define VRAM_BANK2_END  0x007FFFFC

#define SIZE_OF_OPB          ((16) * ( 640/32 ) * ( 480/32 ) * 4)
#define SIZE_OF_BACKGROUND   0x3C
#define SIZE_OF_REGION_ARRAY 0x1C20
#define SIZE_OF_FRAMEBUFFER  0x96000 /* 640x480 * 2 Bytes if 565 colors */

#define RGB565(r, g, b) (uint16_t)((r >> 3) << 11)| ((g >> 2) << 5)| ((b >> 3) << 0)
#define RGB555(r, g, b) (uint16_t)((r >> 3) << 10)| ((g >> 3) << 5)| ((b >> 3) << 0)
#define RGB888(r, g, b) (uint32_t)((0xFF << 24)| (r << 16)| (g << 8)| (b << 0))


void initGraphics()
{
    constexpr auto VGA       = 0;
    constexpr auto NONE      = 1;
    constexpr auto RGB       = 2;
    constexpr auto COMPOSITE = 3;

    constexpr auto BPP    = 16;
    constexpr auto WIDTH  = 640;
    constexpr auto HEIGHT = 480;

    volatile uint32_t *porta = (uint32_t*)0xff80002c;
    *porta = (*(uint32_t*)0xff80002c & ~0xf0000) | 0xa0000;

    switch( ((*(volatile uint16_t*)(porta+1))>>8)&3 )
    {
        case VGA:
        {
            SPG_LOAD       = 524 << 16 | 857 << 0;
            SPG_HBLANK     = 126 << 16 | 837 << 0;
            SPG_VBLANK     =  40 << 16 | 520 << 0;
            SPG_WIDTH      = 504 << 22 | 403 << 12 | 1 << 8 | 63 << 0;
            SPG_CONTROL    =   1 << 8;
            SPG_VBLANK_INT =  21 << 16;

            /* Framebuffer settings */
            FB_R_CTRL       = ( 1 << 23 | 1 << 2 | 1 << 0 );
            FB_R_SIZE       = (                                 1 << 20
                               |                   ( HEIGHT - 1 ) << 10
                               | ( ( WIDTH * (32 / BPP) )/4 - 1 ) << 0 );

            FB_W_CTRL       = ( 1 << 0 );
            FB_W_LINESTRIDE = (WIDTH * (32 / BPP))/8;
            FB_BURSTCTRL    = 0x00093f39;
            FB_X_CLIP       = 0x02800000;
            FB_Y_CLIP       = 0x01e00000;

            VO_STARTX     = 168 << 0;
            VO_STARTY     = 640 << 16 | 40 << 0;
            VO_CONTROL    =  22 << 16;
            VO_BORDER_COL = 0x00000000;
        } break;

        case COMPOSITE:
        {
            SPG_LOAD    = 0x020C0359;
            SPG_HBLANK  = 0x007E0345;
            SPG_VBLANK  = 0x00240204;
            SPG_WIDTH   = 0x07D6C63F;
            SPG_CONTROL = 0x00000150;
            SPG_VBLANK_INT = 21 << 16 | 258 << 0;

            /* Framebuffer settings */
            FB_R_CTRL       = ( 1 << 0 | 1 << 2 );
            FB_R_SIZE       = (   ((WIDTH * (32 / BPP) >> 2) + 1) << 20
                               |                 ( HEIGHT/2 - 1 ) << 10
                               | ( ( WIDTH * (32 / BPP) )/4 - 1 ) << 0 );

            FB_W_CTRL       = ( 1 << 0 );
            FB_W_LINESTRIDE = (WIDTH * (32 / BPP))/8;
            FB_BURSTCTRL    = 0x00093f39;
            FB_X_CLIP       = 0x02800000;
            FB_Y_CLIP       = 0x01e00000;

            VO_STARTX     = 0x000000A4;
            VO_STARTY     = 0x00120012;
            VO_CONTROL    = 0x00160000;
            VO_BORDER_COL = 0x00000000;
        } break;

        default:
        {
            /* ERROR */
        } break;
    }

    SDRAM_CFG      = 0x15F28997;
    SDRAM_ARB_CFG;
    SDRAM_REFRESH  = 0x00000020;

    ISP_FEED_CFG   = 0x00800408 | ( 1 << 3 );
    SPAN_SORT_CFG  = 1 << 1 | 1 << 0;

    FPU_SHAD_SCALE = 0x00000000;
    FPU_PARAM_CFG  = 0x0027df77;
    FPU_CULL_VAL   = 0x3F800000;
    FPU_PERP_VAL   = 0x00000000;

    HALF_OFFSET    = 0x00000007;
    TEXT_CONTROL   = 0x00000001;
    PT_ALPHA_REF   = 0x000000FF;
}


void regionArray()
{
    // Create Region Array
    uint32_t *region_array = (uint32_t*)( VRAM_BASE + VRAM_BANK2_BASE + SIZE_OF_OPB );

    for(int y=0; y<(480/32); y++)
        for(int x=0; x<(640/32); x++)
        {
            const int cur_tile = x + y * ( 640 / 32 );

            /* Note: end-of-list on the last tile! */
            if (x == (640/32)-1 && y == (480/32)-1)
                *region_array++ = 0x80000000 | (y << 8) | (x << 2);
            else
                *region_array++ = (y << 8) | (x << 2);

            *region_array++ = VRAM_BANK2_BASE + ( ( (     0 + 16 * cur_tile ) * 4 )              );
            *region_array++ = VRAM_BANK2_BASE + ( ( (  4256 +  8 * cur_tile ) * 4 ) | 0x80000000 );
            *region_array++ = VRAM_BANK2_BASE + ( ( (  6384 + 16 * cur_tile ) * 4 ) | 0x80000000 );
            *region_array++ = VRAM_BANK2_BASE + ( ( ( 10640 +  8 * cur_tile ) * 4 ) | 0x80000000 );
            *region_array++ = VRAM_BANK2_BASE + ( ( ( 12768 + 16 * cur_tile ) * 4 ) | 0x80000000 );
        }
}


void background()
{
    uint32_t *background = (uint32_t*)(VRAM_BASE + VRAM_BANK2_BASE + SIZE_OF_OPB + SIZE_OF_REGION_ARRAY);

    ISP_BACKGND_T   = 0x01000000 | ( ( VRAM_BANK2_BASE + SIZE_OF_OPB + SIZE_OF_REGION_ARRAY ) << 1 );
    ISP_BACKGND_D   = 0x3F800000;

    *background++ = 0x90800000; /* ISP/TSP Instruction Word */
    *background++ = 0x20800440; /* TSP Instruction Word     */
    *background++ = 0x00000000; /* Texture Control Word     */

    *background++ = 0x00000000;
    *background++ = 0x00000000;
    *background++ = 0x3F800000;
    *background++ = RGB888(0xFF, 0x00, 0x00);

    *background++ = 0x00000000;
    *background++ = 0x43F00000;
    *background++ = 0x3F800000;
    *background++ = RGB888(0x00, 0xFF, 0x00);

    *background++ = 0x44200000;
    *background++ = 0x00000000;
    *background++ = 0x3F800000;
    *background++ = RGB888(0x00, 0x00, 0xFF);
}


int main()
{
    initGraphics();
    regionArray();
    background();

    FB_R_SOF1 = VRAM_BANK2_BASE + SIZE_OF_OPB + SIZE_OF_REGION_ARRAY + SIZE_OF_BACKGROUND;
    FB_W_SOF1 = VRAM_BANK2_BASE + SIZE_OF_OPB + SIZE_OF_REGION_ARRAY + SIZE_OF_BACKGROUND;

    while(true)
    {
        PARAM_BASE  = 0x00000000;
        REGION_BASE = VRAM_BANK2_BASE + SIZE_OF_OPB;

        SOFTRESET = 1;
        SOFTRESET = 0;

        TA_GLOB_TILE_CLIP  = (480/32-1) << 16 | (640/32-1);
        TA_ALLOC_CTRL      = 0x00000002;

        TA_ISP_BASE        = 0x00000000;
        TA_ISP_LIMIT       = SIZE_OF_OPB + SIZE_OF_BACKGROUND + SIZE_OF_REGION_ARRAY + SIZE_OF_FRAMEBUFFER;

        TA_OL_BASE         = VRAM_BANK2_BASE;
        TA_OL_LIMIT        = VRAM_BANK2_BASE + SIZE_OF_OPB;

        TA_LIST_INIT       = 0x80000000;
        TA_LIST_INIT;


        // Wait for bus.
        SB_ISTNRM = 0x08;
        while(!(SB_ISTNRM & 0x08)) {};
        SB_ISTNRM = 0x08;

        STARTRENDER = 0xFFFFFFFF;
    }
}