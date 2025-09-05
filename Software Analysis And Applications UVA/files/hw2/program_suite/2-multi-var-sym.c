#include <stdio.h>
#include <klee/klee.h>

int main() {
    char a[10];
    klee_make_symbolic(a, sizeof(a), "a");

    for (int i = 0; i < 10; i++){
         klee_assume(a[i] == 'A' || a[i] == 'B' || a[i] == 'C' || a[i] == 'D');
    }
    
    int countA = 0;
    for (int i = 0; i < 10; i++){
         if(a[i] == 'A')
             countA++;
    }
    

    if(countA == 5)
         printf("Match!\n");
    else
         printf("No match.\n");
    
    return 0;
}