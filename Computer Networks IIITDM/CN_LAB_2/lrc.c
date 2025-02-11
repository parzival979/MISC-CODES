#include <stdio.h>
#include <stdlib.h>
//LRC ASSUMING EVEN PARITY
int main(){
    int menuOption;
    printf("Please enter 1 for sending or 2 for receiving\n");
    scanf("%d",&menuOption);
    if(menuOption==1){
        int numberOfDataBits;
        printf("Please enter the number of data bits in the multiple of 4\n");
        scanf("%d",&numberOfDataBits);
        int data[numberOfDataBits];
        printf("Please enter the data bits from left to right\n");
        for (int i = 0; i < numberOfDataBits; ++i) {
            printf("Please enter the bit\n");
            scanf("%d",&data[i]);
        }
        int lrcBitsArr[4];
        for (int i = 0; i < 4; ++i) {
            lrcBitsArr[i]=0;
            for (int j = 0; j < numberOfDataBits/4; ++j) {
                lrcBitsArr[i]+=data[j*4+i];
            }
            if(lrcBitsArr[i]%2==0){
                lrcBitsArr[i]=0;
            }
            else{
                lrcBitsArr[i]=1;
            }
        }
        printf("The required Result including lrc bits is\n");
        for (int i = 0; i < numberOfDataBits; ++i) {
            printf("%d",data[i]);
        }
        for (int i = 0; i < 4; ++i) {
            printf("%d",lrcBitsArr[i]);
        }
        printf("\n");
    }
    else if(menuOption==2){
        int numberOfDataBits;
        printf("Please enter the number of data bits in the multiple of 4 including lrc bits\n");
        scanf("%d",&numberOfDataBits);
        int data[numberOfDataBits];
        printf("Please enter the data bits from left to right including lrc bits\n");
        for (int i = 0; i < numberOfDataBits; ++i) {
            printf("Please enter the bit\n");
            scanf("%d",&data[i]);
        }
        int lrcBitsArr[4];
        for (int i = 0; i < 4; ++i) {
            lrcBitsArr[i]=0;
            for (int j = 0; j < (numberOfDataBits/4)-1; ++j) {
                lrcBitsArr[i]+=data[j*4+i];
            }
            if(lrcBitsArr[i]%2==0){
                lrcBitsArr[i]=0;
            }
            else{
                lrcBitsArr[i]=1;
            }
        }
        for (int i = 0; i < 4; ++i) {
            if(data[numberOfDataBits-4+i]==lrcBitsArr[i])
                continue;
            else{
                printf("rejected");
                exit(0);
            }
        }
        printf("Accepted\n");
        printf("The required Result is\n");
        for (int i = 0; i < numberOfDataBits-4 ; ++i) {
            printf("%d",data[i]);
        }
        printf("\n");

    }
    else{
        printf("invalid menu option selected\n");
    }
}