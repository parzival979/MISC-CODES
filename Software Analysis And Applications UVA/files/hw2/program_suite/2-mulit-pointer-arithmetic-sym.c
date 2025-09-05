#include <stdio.h>
#include <klee/klee.h>

int main() {
    int state = 0;
    
    for (int i = 0; i < 12; i++) {
        unsigned char choice;
        klee_make_symbolic(&choice, sizeof(choice), "choice");

        klee_assume(choice < 3);
        if (choice == 0)
            state += 1;    
        else if (choice == 1)
            state += 2;    
        else
            state -= 1;    
    }
    
    
    if (state == 7)
        printf("Target reached\n");
    else
        printf("Target not reached\n");

    return 0;
}