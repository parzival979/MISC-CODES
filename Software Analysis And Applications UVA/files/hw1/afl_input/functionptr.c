#include <stdio.h>

typedef int (*func_ptr)(int, int);

int add(int a, int b) {
    return a + b;
}

int main(void) {
    func_ptr f = add;
    printf("Function pointer call: %d\n", f(10, 20));
    return 0;
}