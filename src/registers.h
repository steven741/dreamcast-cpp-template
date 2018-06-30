#ifndef REGISTERS_H_INCLUDED
#define REGISTERS_H_INCLUDED

#include <cstdint>


/* pg. 26 */
#define PTEH   *( volatile uint32_t *volatile )0xFF000000
#define PTEL   *( volatile uint32_t *volatile )0xFF000004
#define TTB    *( volatile uint32_t *volatile )0xFF000008
#define TEA    *( volatile uint32_t *volatile )0xFF00000C
#define MMUCR  *( volatile uint32_t *volatile )0xFF000010
#define BASRA  *(  volatile uint8_t *volatile )0xFF000014
#define BASRB  *(  volatile uint8_t *volatile )0xFF000018
#define CCR    *( volatile uint32_t *volatile )0xFF00001C
#define TRA    *( volatile uint32_t* )0xFF000020
#define EXPEVT *( volatile uint32_t* )0xFF000024
#define INTEVT *( volatile uint32_t* )0xFF000028
#define PTEA   *( volatile uint32_t* )0xFF000034
#define QACR0  *( volatile uint32_t* )0xFF000038
#define QACR1  *( volatile uint32_t* )0xFF00003C
#define BARA   *( volatile uint32_t* )0xFF200000
#define BAMRA  *( volatile uint32_t* )0xFF200004

#define PCTRA  *( volatile uint16_t* )0xFF80002C

#define CHCR2  *( volatile uint32_t* )0xFFA0002C /* SH4-DMAC-CHCR2 pg. 30 */
#define DMAOR  *( volatile uint32_t* )0xFFA00040



/**
    Main System Bus Registers
*/
#define SB_C2DSTAT                 *( volatile uint32_t* )0xA05F6800
#define SB_C2DLEN                  *( volatile uint32_t* )0xA05F6804
#define SB_C2DST                   *( volatile uint32_t* )0xA05F6808
#define SB_SDSTAW                  *( volatile uint32_t* )0xA05F6810
#define SB_SDBAAW                  *( volatile uint32_t* )0xA05F6814
#define SB_SDWLT                   *( volatile uint32_t* )0xA05F6818
#define SB_SDLAS                   *( volatile uint32_t* )0xA05F681C
#define SB_SDST                    *( volatile uint32_t* )0xA05F6820
#define SB_DBREQM                  *( volatile uint32_t* )0xA05F6840
#define SB_BAVLWC                  *( volatile uint32_t* )0xA05F6844
#define SB_C2DPRYC                 *( volatile uint32_t* )0xA05F6848
#define SB_C2DMAXL                 *( volatile uint32_t* )0xA05F684C
#define SB_TFREM             *( const volatile uint32_t* )0xA05F6880
#define SB_LMMODE0                 *( volatile uint32_t* )0xA05F6884
#define SB_LMMODE1                 *( volatile uint32_t* )0xA05F6888
#define SB_FFST              *( const volatile uint32_t* )0xA05F688C
#define SB_SFRES                   *( volatile uint32_t* )0xA05F6890 /* write only */
#define SB_SBREV             *( const volatile uint32_t* )0xA05F689C
#define SB_RBSPLT                  *( volatile uint32_t* )0xA05F68A0
#define SB_ISTNRM                  *( volatile uint32_t* )0xA05F6900
#define SB_ISTEXT            *( const volatile uint32_t* )0xA05F6904
#define SB_ISTERR                  *( volatile uint32_t* )0xA05F6908
#define SB_IML2NRM                 *( volatile uint32_t* )0xA05F6910
#define SB_IML2EXT                 *( volatile uint32_t* )0xA05F6914
#define SB_IML2ERR                 *( volatile uint32_t* )0xA05F6918
#define SB_IML4NRM                 *( volatile uint32_t* )0xA05F6920
#define SB_IML4EXT                 *( volatile uint32_t* )0xA05F6924
#define SB_IML4ERR                 *( volatile uint32_t* )0xA05F6928
#define SB_IML6NRM                 *( volatile uint32_t* )0xA05F6930
#define SB_IML6EXT                 *( volatile uint32_t* )0xA05F6934
#define SB_IML6ERR                 *( volatile uint32_t* )0xA05F6938
#define SB_PDTNRM                  *( volatile uint32_t* )0xA05F6940
#define SB_PDTEXT                  *( volatile uint32_t* )0xA05F6944
#define SB_G2DTNRM                 *( volatile uint32_t* )0xA05F6950
#define SB_G2DTEXT                 *( volatile uint32_t* )0xA05F6954

/**
    Maple System Bus Register
*/
#define SB_MDSTAR                  *( volatile uint32_t* )0xA05F6C04
#define SB_MDTSEL                  *( volatile uint32_t* )0xA05F6C10
#define SB_MDEN                    *( volatile uint32_t* )0xA05F6C14
#define SB_MDST                    *( volatile uint32_t* )0xA05F6C18
#define SB_MSYS                    *( volatile uint32_t* )0xA05F6C80
#define SB_MST               *( const volatile uint32_t* )0xA05F6C84
#define SB_MSHTCL                  *( volatile uint32_t* )0xA05F6C88 /* write only */
#define SB_MDAPRO                  *( volatile uint32_t* )0xA05F6C8C /* write only */
#define SB_MMSEL                   *( volatile uint32_t* )0xA05F6CE8
#define SB_MTXDAD            *( const volatile uint32_t* )0xA05F6CF4
#define SB_MRXDAD            *( const volatile uint32_t* )0xA05F6CF8
#define SB_MRXDBD            *( const volatile uint32_t* )0xA05F6CFC

/**
    G1 Interface Registers
*/
#define SB_GDSTAR                  *( volatile uint32_t* )0xA05F7404
#define SB_GDLEN                   *( volatile uint32_t* )0xA05F7408
#define SB_GDDIR                   *( volatile uint32_t* )0xA05F740C
#define SB_GDEN                    *( volatile uint32_t* )0xA05F7414
#define SB_GDST                    *( volatile uint32_t* )0xA05F7418
#define SB_G1RRC                   *( volatile uint32_t* )0xA05F7480 /* write only */
#define SB_G1RWC                   *( volatile uint32_t* )0xA05F7484 /* write only */
#define SB_G1FRC                   *( volatile uint32_t* )0xA05F7488 /* write only */
#define SB_G1FWC                   *( volatile uint32_t* )0xA05F748C /* write only */
#define SB_G1CRC                   *( volatile uint32_t* )0xA05F7490 /* write only */
#define SB_G1CWC                   *( volatile uint32_t* )0xA05F7494 /* write only */
#define SB_G1GDRC                  *( volatile uint32_t* )0xA05F74A0 /* write only */
#define SB_G1GDWC                  *( volatile uint32_t* )0xA05F74A4 /* write only */
#define SB_G1SYSM            *( const volatile uint32_t* )0xA05F74B0
#define SB_G1CRDYC                 *( volatile uint32_t* )0xA05F74B4 /* write only */
#define SB_GDAPRO                  *( volatile uint32_t* )0xA05F74B8 /* write only */
#define SB_GDSTARD           *( const volatile uint32_t* )0xA05F74F4
#define SB_GDLEND            *( const volatile uint32_t* )0xA05F74F8

/**
    G2 Interface Registers
*/
#define SB_ADSTAG                  *( volatile uint32_t* )0xA05F7800
#define SB_ADSTAR                  *( volatile uint32_t* )0xA05F7804
#define SB_ADLEN                   *( volatile uint32_t* )0xA05F7808
#define SB_ADDIR                   *( volatile uint32_t* )0xA05F780C
#define SB_ADTSEL                  *( volatile uint32_t* )0xA05F7810
#define SB_ADEN                    *( volatile uint32_t* )0xA05F7814
#define SB_ADST                    *( volatile uint32_t* )0xA05F7818
#define SB_ADSUSP                  *( volatile uint32_t* )0xA05F781C
#define SB_E1STAG                  *( volatile uint32_t* )0xA05F7820
#define SB_E1STAR                  *( volatile uint32_t* )0xA05F7824
#define SB_E1LEN                   *( volatile uint32_t* )0xA05F7828
#define SB_E1DIR                   *( volatile uint32_t* )0xA05F782C
#define SB_E1TSEL                  *( volatile uint32_t* )0xA05F7830
#define SB_E1EN                    *( volatile uint32_t* )0xA05F7834
#define SB_E1ST                    *( volatile uint32_t* )0xA05F7838
#define SB_E1SUSP                  *( volatile uint32_t* )0xA05F783C
#define SB_E2STAG                  *( volatile uint32_t* )0xA05F7840
#define SB_E2STAR                  *( volatile uint32_t* )0xA05F7844
#define SB_E2LEN                   *( volatile uint32_t* )0xA05F7848
#define SB_E2DIR                   *( volatile uint32_t* )0xA05F784C
#define SB_E2TSEL                  *( volatile uint32_t* )0xA05F7850
#define SB_E2EN                    *( volatile uint32_t* )0xA05F7854
#define SB_E2ST                    *( volatile uint32_t* )0xA05F7858
#define SB_E2SUSP                  *( volatile uint32_t* )0xA05F785C
#define SB_DDSTAG                  *( volatile uint32_t* )0xA05F7860
#define SB_DDSTAR                  *( volatile uint32_t* )0xA05F7864
#define SB_DDLEN                   *( volatile uint32_t* )0xA05F7868
#define SB_DDDIR                   *( volatile uint32_t* )0xA05F786C
#define SB_DDTSEL                  *( volatile uint32_t* )0xA05F7870
#define SB_DDEN                    *( volatile uint32_t* )0xA05F7874
#define SB_DDST                    *( volatile uint32_t* )0xA05F7878
#define SB_DDSUSP                  *( volatile uint32_t* )0xA05F787C
#define SB_G2ID              *( const volatile uint32_t* )0xA05F7880
#define SB_G2DSTO                  *( volatile uint32_t* )0xA05F7890
#define SB_G2TRTO                  *( volatile uint32_t* )0xA05F7894
#define SB_G2MDMTO                 *( volatile uint32_t* )0xA05F7898
#define SB_G2MDMW                  *( volatile uint32_t* )0xA05F789C
#define SB_G2APRO                  *( volatile uint32_t* )0xA05F78BC /* write only */
#define SB_ADSTAGD           *( const volatile uint32_t* )0xA05F78C0
#define SB_ADSTARD           *( const volatile uint32_t* )0xA05F78C4
#define SB_ADLEND            *( const volatile uint32_t* )0xA05F78C8
#define SB_E1STAGD           *( const volatile uint32_t* )0xA05F78D0
#define SB_E1STARD           *( const volatile uint32_t* )0xA05F78D4
#define SB_E1LEND            *( const volatile uint32_t* )0xA05F78D8
#define SB_E2STAGD           *( const volatile uint32_t* )0xA05F78E0
#define SB_E2STARD           *( const volatile uint32_t* )0xA05F78E4
#define SB_E2LEND            *( const volatile uint32_t* )0xA05F78E8
#define SB_DDSTAGD           *( const volatile uint32_t* )0xA05F78F0
#define SB_DDSTARD           *( const volatile uint32_t* )0xA05F78F4
#define SB_DDLEND            *( const volatile uint32_t* )0xA05F78F8

/**
    PowerVR System Bus Registers
*/
#define SB_PDSTAP                  *( volatile uint32_t* )0xA05F7C00
#define SB_PDSTAR                  *( volatile uint32_t* )0xA05F7C04
#define SB_PDLEN                   *( volatile uint32_t* )0xA05F7C08
#define SB_PDDIR                   *( volatile uint32_t* )0xA05F7C0C
#define SB_PDTSEL                  *( volatile uint32_t* )0xA05F7C10
#define SB_PDEN                    *( volatile uint32_t* )0xA05F7C14
#define SB_PDST                    *( volatile uint32_t* )0xA05F7C18
#define SB_PDAPRO                  *( volatile uint32_t* )0xA05F7C80 /* write only */
#define SB_PDSTAPD           *( const volatile uint32_t* )0xA05F7CF0
#define SB_PDSTARD           *( const volatile uint32_t* )0xA05F7CF4
#define SB_PDLEND            *( const volatile uint32_t* )0xA05F7CF8

/**
    Core Registers
*/
#define HOLLY_ID    	        *( const volatile uint32_t* )0xA05F8000
#define HOLLY_REVISION		    *( const volatile uint32_t* )0xA05F8004
#define SOFTRESET                     *( volatile uint32_t* )0xA05F8008
#define STARTRENDER                   *( volatile uint32_t* )0xA05F8014
#define TEST_SELECT                   *( volatile uint32_t* )0xA05F8018
#define PARAM_BASE                    *( volatile uint32_t* )0xA05F8020
#define REGION_BASE                   *( volatile uint32_t* )0xA05F802C
#define SPAN_SORT_CFG                 *( volatile uint32_t* )0xA05F8030
#define VO_BORDER_COL                 *( volatile uint32_t* )0xA05F8040
#define FB_R_CTRL                     *( volatile uint32_t* )0xA05F8044
#define FB_W_CTRL                     *( volatile uint32_t* )0xA05F8048
#define FB_W_LINESTRIDE               *( volatile uint32_t* )0xA05F804C
#define FB_R_SOF1                     *( volatile uint32_t* )0xA05F8050
#define FB_R_SOF2                     *( volatile uint32_t* )0xA05F8054
#define FB_R_SIZE                     *( volatile uint32_t* )0xA05F805C
#define FB_W_SOF1                     *( volatile uint32_t* )0xA05F8060
#define FB_W_SOF2                     *( volatile uint32_t* )0xA05F8064
#define FB_X_CLIP                     *( volatile uint32_t* )0xA05F8068
#define FB_Y_CLIP                     *( volatile uint32_t* )0xA05F806C
#define FPU_SHAD_SCALE                *( volatile uint32_t* )0xA05F8074
#define FPU_CULL_VAL                  *( volatile uint32_t* )0xA05F8078
#define FPU_PARAM_CFG                 *( volatile uint32_t* )0xA05F807C
#define HALF_OFFSET                   *( volatile uint32_t* )0xA05F8080
#define FPU_PERP_VAL                  *( volatile uint32_t* )0xA05F8084
#define ISP_BACKGND_D                 *( volatile uint32_t* )0xA05F8088
#define ISP_BACKGND_T                 *( volatile uint32_t* )0xA05F808C
#define ISP_FEED_CFG                  *( volatile uint32_t* )0xA05F8098
#define SDRAM_REFRESH                 *( volatile uint32_t* )0xA05F80A0
#define SDRAM_ARB_CFG                 *( volatile uint32_t* )0xA05F80A4
#define SDRAM_CFG                     *( volatile uint32_t* )0xA05F80A8
#define FOG_COL_RAM                   *( volatile uint32_t* )0xA05F80B0
#define FOG_COL_VERT                  *( volatile uint32_t* )0xA05F80B4
#define FOG_DENSITY                   *( volatile uint32_t* )0xA05F80B8
#define FOG_CLAMP_MAX                 *( volatile uint32_t* )0xA05F80BC
#define FOG_CLAMP_MIN                 *( volatile uint32_t* )0xA05F80C0
#define SPG_TRIGGER_POS               *( volatile uint32_t* )0xA05F80C4
#define SPG_HBLANK_INT                *( volatile uint32_t* )0xA05F80C8
#define SPG_VBLANK_INT                *( volatile uint32_t* )0xA05F80CC
#define SPG_CONTROL                   *( volatile uint32_t* )0xA05F80D0
#define SPG_HBLANK                    *( volatile uint32_t* )0xA05F80D4
#define SPG_LOAD                      *( volatile uint32_t* )0xA05F80D8
#define SPG_VBLANK                    *( volatile uint32_t* )0xA05F80DC
#define SPG_WIDTH                     *( volatile uint32_t* )0xA05F80E0
#define TEXT_CONTROL                  *( volatile uint32_t* )0xA05F80E4
#define VO_CONTROL                    *( volatile uint32_t* )0xA05F80E8
#define VO_STARTX                     *( volatile uint32_t* )0xA05F80EC
#define VO_STARTY                     *( volatile uint32_t* )0xA05F80F0
#define SCALER_CTL                    *( volatile uint32_t* )0xA05F80F4
#define PAL_RAM_CTRL                  *( volatile uint32_t* )0xA05F8108
#define SPG_STATUS              *( const volatile uint32_t* )0x005F810C
#define FB_BURSTCTRL                  *( volatile uint32_t* )0xA05F8110
#define FB_C_SOF                *( const volatile uint32_t* )0x005F8114
#define Y_COEFF                       *( volatile uint32_t* )0xA05F8118
#define PT_ALPHA_REF                  *( volatile uint32_t* )0xA05F811C
#define TA_OL_BASE                    *( volatile uint32_t* )0xA05F8124

/**
    Tile Accelerator Registers
*/
#define TA_ISP_BASE                   *( volatile uint32_t* )0xA05F8128
#define TA_OL_LIMIT                   *( volatile uint32_t* )0xA05F812C
#define TA_ISP_LIMIT                  *( volatile uint32_t* )0xA05F8130
#define TA_NEXT_OPB             *( const volatile uint32_t* )0x005F8134
#define TA_ITP_CURRENT          *( const volatile uint32_t* )0x005F8138
#define TA_GLOB_TILE_CLIP             *( volatile uint32_t* )0xA05F813C
#define TA_ALLOC_CTRL                 *( volatile uint32_t* )0xA05F8140
#define TA_LIST_INIT                  *( volatile uint32_t* )0xA05F8144
#define TA_YUV_TEX_BASE               *( volatile uint32_t* )0xA05F8148
#define TA_YUV_TEX_CTRL               *( volatile uint32_t* )0xA05F814C
#define TA_YUV_TEX_CNT          *( const volatile uint32_t* )0x005F8150
#define TA_LIST_CONT                  *( volatile uint32_t* )0xA05F8160
#define TA_NEXT_OPB_INIT              *( volatile uint32_t* )0xA05F8164
#define TA_OL_POINTERS          *( const volatile uint32_t* )0x005F8F5C

#endif /* REGISTERS_H_INCLUDED */