int main() {
    int a = 10, b;
    asm ("movl %1, %0" : "=r"(b) : "r"(a));
    return b;
}