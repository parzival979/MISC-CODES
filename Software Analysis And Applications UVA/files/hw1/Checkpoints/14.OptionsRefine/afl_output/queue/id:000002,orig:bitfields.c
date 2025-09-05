#include <stdio.h>

struct BitTest {
    unsigned int a: 1;
    signed int b: 3;
    unsigned long long c: 33; 
    int normal;
};

int main(void) {
    struct BitTest bt = {1, -4, 123456789ULL, 77};
    printf("%d %d %llu %d\n", bt.a, bt.b, (unsigned long long)bt.c, bt.normal);
    return 0;
}