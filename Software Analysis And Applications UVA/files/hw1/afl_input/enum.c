#include <stdio.h>

enum my_enum {
    VAL_A = 1,
    VAL_B,
    VAL_C
};

#define TYPE_NAME(x) _Generic((x), \
    int: "int", \
    float: "float", \
    double: "double", \
    default: "unknown")

int main() {
    int x = 10;
    double y = 5.5;
    
    printf("Type of x: %s\n", TYPE_NAME(x));
    printf("Type of y: %s\n", TYPE_NAME(y));
    printf("Enum value: %d\n", VAL_B);

    return 0;
}