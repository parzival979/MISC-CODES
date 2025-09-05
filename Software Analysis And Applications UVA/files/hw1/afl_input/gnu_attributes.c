#include <stdio.h>

__attribute__((constructor)) void init() {
    printf("Constructor function executed.\n");
}

__attribute__((section(".mysection"))) int special_var = 42;

void __attribute__((noreturn)) test_noreturn() {
    printf("This function should never return.\n");
    while (1);
}

int main() {
    printf("Special var: %d\n", special_var);
    test_noreturn();
}