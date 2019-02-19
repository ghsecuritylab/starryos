#include <machine/asm.h>

/*  unsigned inb(U16_t port); */
/*  unsigned inl(U16_t port); */
/*  void intr_disable(void); */
/*  void intr_enable(void); */
/*  unsigned inw(U16_t port); */
/*  void outb(U16_t port, U8_t value); */
/*  void outl(U16_t port, u32_t value); */
/*  void outw(U16_t port, U16_t value); */

ENTRY(inb)
    push    %ebp
    movl    %esp, %ebp
    movl    8(%ebp), %edx   /* port */
    xorl    %eax, %eax
    inb %dx /* read 1 byte */
    pop %ebp
    ret 

ENTRY(inl)
    push    %ebp
    movl    %esp, %ebp
    movl    8(%ebp), %edx   /* port */
    inl %dx /* read 1 dword */
    pop %ebp
    ret

   
ENTRY(intr_disable)
    cli
    ret 
    
ENTRY(intr_enable)
    sti
    ret

ENTRY(inw)
    push    %ebp
    movl    %esp, %ebp
    movl    8(%ebp), %edx   /* port */
    xorl    %eax, %eax
    inw %dx /* read 1 word */
    pop %ebp
    ret

ENTRY(outb)
    push    %ebp
    movl    %esp, %ebp
    movl    8(%ebp), %edx   /* port */
    movl    8+4(%ebp), %eax /* value */
    outb    %dx /* output 1 byte */
    pop %ebp
    ret

ENTRY(outl)
    push    %ebp
    movl    %esp, %ebp
    movl    8(%ebp), %edx   /* port */
    movl    8+4(%ebp), %eax /* value */
    outl    %dx /* output 1 dword */
    pop %ebp
    ret


ENTRY(outw)
    push    %ebp
    movl    %esp, %ebp
    movl    8(%ebp), %edx   /* port */
    movl    8+4(%ebp), %eax /* value */
    outw    %dx /* output 1 word */
    pop %ebp
    ret


