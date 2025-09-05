#include <stdio.h>
#include <klee/klee.h>

int main() {
    int arr[5];
    klee_make_symbolic(arr, sizeof(arr), "arr");

    for (int i = 0; i < 5; i++) {
        klee_assume(arr[i] >= 0);
        klee_assume(arr[i] <= 100);
    }

    int sorted = 1;
    for (int i = 0; i < 4; i++) {
        if (arr[i] > arr[i+1]) {
            sorted = 0;
            break;
        }
    }

    if (sorted)
        printf("Array is sorted\n");
    else
        printf("Array is not sorted\n");

    return 0;
}