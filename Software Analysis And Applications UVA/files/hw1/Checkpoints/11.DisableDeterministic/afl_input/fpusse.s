.section .text
.global _start
_start:
    fldz
    fadd st(0), st(0)
    fstp %st(0)
    ret