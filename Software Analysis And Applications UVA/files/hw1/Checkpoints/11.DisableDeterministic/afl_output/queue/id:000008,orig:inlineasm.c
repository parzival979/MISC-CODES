int main    asm ("movl %1, %0" : "=r"(b) : "r"(a));
    return b