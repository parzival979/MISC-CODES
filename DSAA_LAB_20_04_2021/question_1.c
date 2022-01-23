// QUESTION 1
//DECLARING THE REQUIRED LIBRARIES
#include<stdio.h>
#include<stdlib.h>
//FUNCTION PROTOTYPES
void encryption(int *matrix_,int rows_,int columns_);
void decryption(int *matrix_,int rows_,int columns_);
int main(void) {
    int rows_, columns_;
    //TAKING INPUT OF ROWS AND COLUMNS OF MATRIX
    printf("PLEASE ENTER THE ROWS OF THE MATRIX\n");
    scanf("%d", &rows_);
    printf("PLEASE ENTER THE COLUMNS OF THE MATRIX\n");
    scanf("%d", &columns_);
    //DYNAMIC MEMORY ALLOCATION
    int *matrix_ = (int *) malloc(rows_ * columns_ * sizeof(int));
    //TAKING INPUT INTO THE 2D ARRAY
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < columns_; ++j) {
            printf("PLEASE ENTER THE ELEMENT %d,%d OF THE ARRAY\n", i, j);
            scanf("%d", (matrix_ + (i * columns_) + j));
        }
    }
    //ASKING FOR ENCRYPTION OR DECRYPTION
    int enc_or_dec;
    printf("ENTER 1 FOR ENCRYPTION OR ANY OTHER NUMBER FOR DECRYPTION\n");
    scanf("%d", &enc_or_dec);
    if (enc_or_dec == 1) {
        encryption(matrix_, rows_, columns_);
    } else {
        decryption(matrix_, rows_, columns_);
    }
    // PRINTING THE MATRIX
    printf("THE REQUIRED MATRIX IS\n");
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < columns_; ++j) {
            printf("%d ", *(matrix_ + (i * columns_) + j));
        }
        printf("\n");
    }
    //FREEING THE MEMORY
    free(matrix_);

}
//ENCRYPTION ALGORITHM
void encryption(int *matrix_,int rows_,int columns_){
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < columns_; ++j) {
            if(i==0)
                *(matrix_+(i*columns_)+j) += i;
            else if(j==0)
                *(matrix_+(i*columns_)+j) += i;
            else if(i==rows_-1)
                *(matrix_+(i*columns_)+j) += i;
            else if(j==columns_-1)
                *(matrix_+(i*columns_)+j) += i;
            else
                *(matrix_+(i*columns_)+j) -= (i+j);

        }

    }

}
// DECRYPTION ALGORITHM
void decryption(int *matrix_,int rows_,int columns_){
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < columns_; ++j) {
            if(i==0)
                *(matrix_+(i*columns_)+j) -= i;
            else if(j==0)
                *(matrix_+(i*columns_)+j) -= i;
            else if(i==rows_-1)
                *(matrix_+(i*columns_)+j) -= i;
            else if(j==columns_-1)
                *(matrix_+(i*columns_)+j) -= i;
            else
                *(matrix_+(i*columns_)+j) += (i+j);

        }

    }

}