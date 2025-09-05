#include <stdio.h>
#include <setjmp.h>

static jmp_buf env;

void second(void) {
    longjmp(env, 123);
}

int main(void) {
    if (!setjmp(env)) {
        second();
    } else {
        printf("We jumped back via longjmp.\n");
    }
    return 0;
}