#include <stdio.h>

int main(void) {
#ifdef __GNUC__
    int outer = 5;
    int nested_func(void){
        return outer * 2;
    }
    printf("Nested: %d\n", nested_func());
#else
    printf("No nested functions on this compiler.\n");
#endif
    return 0;
}