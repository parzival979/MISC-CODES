#include <stdio.h>
#include <stdlib.h>
//VRC ASSUMING EVEN PARITY
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
        int vrcBitsArr[numberOfDataBits/4];
        for (int i = 0; i < numberOfDataBits/4; ++i) {
            int curSum = 0;
            for (int j = 4*i; j < (4*i)+4 ; ++j) {
                curSum += data[j];
            }
            if(curSum%2==0)
                vrcBitsArr[i]=0;
            else
                vrcBitsArr[i]=1;
        }
        printf("The required Result including vrc bits is\n");
        for (int i = 0; i < numberOfDataBits; ++i) {
            printf("%d",data[i]);
        }
        for (int i = 0; i < 4; ++i) {
            printf("%d",vrcBitsArr[i]);
        }
        printf("\n");
    }
    else if(menuOption==2){
        int numberOfDataBits;
        printf("Please enter the number of data bits excluding vrc bits\n");
        scanf("%d",&numberOfDataBits);
        int data[numberOfDataBits+numberOfDataBits/4];
        printf("Please enter the data bits from left to right including vrc bits\n");
        for (int i = 0; i < numberOfDataBits+numberOfDataBits/4; ++i) {
            printf("Please enter the bit\n");
            scanf("%d",&data[i]);
        }
        int vrcBitsArr[numberOfDataBits/4];
        for (int i = 0; i < numberOfDataBits/4; ++i) {
            int curSum = 0;
            for (int j = 4*i; j < (4*i)+4 ; ++j) {
                curSum += data[j];
            }
            if(curSum%2==0)
                vrcBitsArr[i]=0;
            else
                vrcBitsArr[i]=1;
        }
        for (int i = 0; i < numberOfDataBits/4; ++i) {
            if(data[numberOfDataBits+i]==vrcBitsArr[i])
                continue;
            else{
                printf("rejected");
                exit(0);
            }
        }
        printf("Accepted\n");
        printf("The required Result is\n");
        for (int i = 0; i < numberOfDataBits ; ++i) {
            printf("%d",data[i]);
        }
        printf("\n");

    }
    else{
        printf("invalid menu option selected\n");
    }
}