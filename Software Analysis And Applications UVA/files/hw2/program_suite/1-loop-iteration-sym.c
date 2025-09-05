#include <stdio.h>
#include <klee/klee.h>

int main() {
    unsigned char x;
    klee_make_symbolic(&x, sizeof(x), "x");
    klee_assume(x <= 9);

    int sum = 0;
    for (int i = 0; i < x; i++) {
        if (i % 2 == 0)
            sum += i;
        else
            sum -= i;
    }

    if (sum > 0)
        printf("Positive sum\n");
    else
        printf("Non-positive sum\n");
    return 0;
}