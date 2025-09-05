#include <stdio.h>
int main() {
    int val = 2;
    switch (val) {
        case 1: printf("One\n"); break;
        case 2: printf("Two\n"); break;
        case 3: printf("Three\n"); break;
        default: printf("Other\n"); break;
    }
    return 0;
}