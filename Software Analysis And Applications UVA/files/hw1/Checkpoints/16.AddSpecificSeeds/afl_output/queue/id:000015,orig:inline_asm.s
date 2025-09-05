int main() {
    __asm__("movl $1, %eax\n"
            "addl $2, %eax\n"
            "ret");
    return 0;
}