#include <stdio.h>
#include <klee/klee.h>

int main() {
    char arr[24];
    klee_make_symbolic(arr, sizeof(arr), "arr");

    int sum = 0;
    
    for (int i = 0; i < 24; i++) {
        if (arr[i] == 'a')
            sum++;
        else
            sum--;
    }

    if (sum == 0)
        printf("Balanced\n");
    else
        printf("Unbalanced\n");

    return 0;
}