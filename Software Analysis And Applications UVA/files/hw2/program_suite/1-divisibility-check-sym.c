#include <stdio.h>
#include <klee/klee.h>

int main() {
    int x;
    klee_make_symbolic(&x, sizeof(x), "x");

    klee_assume(x >= 0);
    klee_assume(x <= 100);

    if (x % 3 == 0)
        printf("Divisible by 3\n");
    else
        printf("Not divisible by 3\n");

    return 0;
}