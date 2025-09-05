.section .text
.global _start
_start:
    movl $10, %eax
    addl $5, %eax
    imull $2, %eax
    subl $3, %eax
    ret