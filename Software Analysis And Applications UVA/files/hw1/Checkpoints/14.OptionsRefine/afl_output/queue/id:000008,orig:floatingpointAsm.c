int main() {
    __asm__("fldz\n"
            "fld1\n"
            "faddp\n"
            "fstp %st(0)");
    return 0;
}