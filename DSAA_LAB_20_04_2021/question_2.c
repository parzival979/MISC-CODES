// QUESTION 2
// DECLARING THE REQUIRED STANDARD LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
    // TAKING THE INPUT OF ORDER OF REQUIRED SYMMETRIC MATRIX
    printf("PLEASE ENTER THE NUMBER OF ROW OR COLUMN ELEMENTS FOR WHICH YOU WANT TO GENERATE THE SYMMETRIC MATRIX\n");
    int nos_;
    scanf("%d",&nos_);
    // CREATING THE ARRAY BY USING DYNAMIC MEMORY ALLOCATION AND TAKING ELEMENTS INTO IT BY RAND FUNCTION
    int *array = (int*) malloc((((nos_)*(nos_+1))/2) * sizeof(int));
    srand(time(0));
    for (int i = 0; i < (((nos_)*(nos_+1))/2) ; ++i) {
        *(array + i) = 10 + rand() % 90;
    }
    // ALGORITHM TO PRINT THE REQUIRED SYMMETRIC MATRIX
    printf("THE REQUIRED SYMMETRIC MATRIX IS\n");
    for (int i = 0; i < nos_; ++i) {
        for (int j = 0; j < nos_; ++j) {
            if(i==j){
                printf("%d ",*(array+((nos_-i)*i)+i));
            }
            else if(j > i){
                printf("%d ",*(array+((nos_-i)*i)+j));

            }
            else if(i > j){
                printf("%d ",*(array+((nos_-j)*j)+i));

            }

        }
        printf("\n");

    }
    //FREEING THE MEMORY ALLOCATED
    free(array);




}