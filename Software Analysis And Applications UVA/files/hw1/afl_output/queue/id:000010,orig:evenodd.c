#include <stdio.h>
int main() {
    int i;
    for (i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            printf("Even: %d\n", i);
        } else {
            printf("Odd: %d\n", i);
        }
    }
    return 0;
}