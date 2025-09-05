#include <stdio.h>
#include <klee/klee.h>

int fib(int x) {
    if (x <= 1) return x;
    return fib(x - 1) + fib(x - 2);
}

int main() {
    unsigned char n;
    klee_make_symbolic(&n, sizeof(n), "n");
    klee_assume(n <= 30);

    int result = fib(n);
    if (result % 2 == 0)
        printf("Even\n");
    else
        printf("Odd\n");

    return 0;
}