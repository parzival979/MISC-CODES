#include <stdio.h>
#include <klee/klee.h>

int main() {
    char arr[10];
    klee_make_symbolic(&arr, sizeof(arr), "arr");

    int count = 0;
    for (int i = 0; i < 100; i++){
        if (arr[i] == 'a')
            count++;
        else
            count--;
    }

    if(count == 0)
        printf("Balanced\n");
    else
        printf("Unbalanced\n");

    return 0;
}