#include <stdio.h>

typedef unsigned long long my_uint64_t;
typedef struct __attribute__((packed)) {
    int a;
    short b;
    my_uint64_t c;
} my_struct;

typedef struct nested_struct {
    int x;
    my_struct inner;
} nested_struct_t;

void test_types(my_struct s) {
    printf("Struct: %d, %d, %llu\n", s.a, s.b, s.c);
}

int main(void) {
    my_struct s = {1, 2, 3};
    nested_struct_t n = {10, {20, 30, 40}};
    
    test_types(s);
    printf("Nested struct: %d, %d, %d, %llu\n", n.x, n.inner.a, n.inner.b, n.inner.c);
    return 0;
}