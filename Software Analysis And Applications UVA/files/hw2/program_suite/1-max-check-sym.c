#include <stdio.h>
#include <klee/klee.h>

int main() {
    int a, b;
    klee_make_symbolic(&a, sizeof(a), "a");
    klee_make_symbolic(&b, sizeof(b), "b");

    if (a > b) {
        printf("a is greater than b\n");
    } else if (a < b) {
        printf("b is greater than a\n");
    } else {
        printf("a is equal to b\n");
    }
    return 0;
}