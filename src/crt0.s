    .globl start
	
    .text

start:
    stc	sr,r0
    or #0xf0,r0
    ldc	r0,sr
    mov.l setup_cache_addr,r0
    mov.l p2_mask,r1
    or r1,r0
    jmp	@r0
    nop

setup_cache:
    mov.l ccr_addr,r0
    mov.w ccr_data,r1
    mov.l r1,@r0

    mov.l initaddr,r0
    mov	#0,r1
    nop
    nop
    nop
    nop
    nop
    nop
    jmp	@r0
    mov	r1,r0

init:
    mov.l bss_start_addr,r0
    mov.l bss_end_addr,r2
    mov	#3,r1
    add	r1,r0
    add	r1,r2
    not	r1,r1
    and	r1,r0
    and	r1,r2
    sub	r0,r2
    shlr r2
    shlr r2
    mov	#0,r1
.loop: dt r2
    mov.l r1,@r0
    bf/s .loop
    add	#4, r0
    mov	#0, r2
    mov	#0, r1
    lds	r1,fpscr
    mov.l stackaddr,r15
    mov.l mainaddr,r0
    jmp	@r0
    mov	r1,r0

    .align 2
mainaddr:
    .long _main
initaddr:
    .long init
stackaddr:
    .long 0x8C010000
bss_start_addr:
    .long __bss_start
bss_end_addr:
    .long _end
p2_mask:
    .long 0xA0000000
setup_cache_addr:
    .long setup_cache
ccr_addr:
    .long 0xFF00001C
ccr_data:
    .word 0x090B

    .end
