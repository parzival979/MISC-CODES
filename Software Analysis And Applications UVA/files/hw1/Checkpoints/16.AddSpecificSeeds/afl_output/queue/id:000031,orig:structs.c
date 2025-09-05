#include <stdio.h>
struct Test {
    int a;
    double b;
};
int main() {
    struct Test x = {10, 3.14};
    printf("%d %f\n", x.a, x.b);
    return 0;
}