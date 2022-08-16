#include <stdio.h>

int main(){
    int menuOption;
    printf("Please enter 1 for sending or 2 for receiving\n");
    scanf("%d",&menuOption);
    if(menuOption==1){
        int degreeOfPolynomial=0;
        printf("Please enter the degree of the polynomial\n");
        scanf("%d",&degreeOfPolynomial);
        int coefficientsArr[degreeOfPolynomial+1];
        printf("Please enter the coefficients of the polynomial\n");
        for (int i = 0; i < degreeOfPolynomial+1; ++i) {
            printf("Please enter the coefficient for x^%d\n",i);
            scanf("%d",&coefficientsArr[degreeOfPolynomial-i]);
            if(coefficientsArr[i]!=0)
                coefficientsArr[i]=1;
        }
        int numberOfDataBits;
        printf("Please enter the number of data bits\n");
        scanf("%d",&numberOfDataBits);
        int data[numberOfDataBits+degreeOfPolynomial];
        int dividend[numberOfDataBits+degreeOfPolynomial];
        for (int i = 0; i < numberOfDataBits+degreeOfPolynomial; ++i) {
            data[i]=0;
            dividend[i]=0;
        }
        printf("Please enter the data bits from left to right\n");
        for (int i = 0; i < numberOfDataBits; ++i) {
            printf("Please enter the bit\n");
            scanf("%d",&data[i]);
            dividend[i]=data[i];
        }

        while(1){
            int first1 = 0;
            while(1){
                if(dividend[first1]==1)
                    break;
                else
                    first1++;
            }
            if(numberOfDataBits+degreeOfPolynomial-first1<=degreeOfPolynomial){
                for (int i = first1; i < numberOfDataBits+degreeOfPolynomial; ++i) {
                    data[i]=dividend[i];
                }
                break;
            }
            else{
                for (int i = first1; i < first1+degreeOfPolynomial+1 ; ++i) {
                    if(dividend[i]!=coefficientsArr[i-first1]){
                        dividend[i]=1;
                    }
                    else
                        dividend[i]=0;
                }
            }
        }
        printf("The required result is\n");
        for(int i = 0; i < numberOfDataBits+degreeOfPolynomial; ++i) {
            printf("%d",data[i]);
        }
        printf("\n");

    }
    else if (menuOption==2){
        int degreeOfPolynomial=0;
        printf("Please enter the degree of the polynomial\n");
        scanf("%d",&degreeOfPolynomial);
        int coefficientsArr[degreeOfPolynomial+1];
        printf("Please enter the coefficients of the polynomial\n");
        for (int i = 0; i < degreeOfPolynomial+1; ++i) {
            printf("Please enter the coefficient for x^%d\n",i);
            scanf("%d",&coefficientsArr[degreeOfPolynomial-i]);
            if(coefficientsArr[i]!=0)
                coefficientsArr[i]=1;
        }
        int numberOfDataBits;
        printf("Please enter the number of data bits including the CRC bits\n");
        scanf("%d",&numberOfDataBits);
        int data[numberOfDataBits+degreeOfPolynomial];
        int dividend[numberOfDataBits+degreeOfPolynomial];
        for (int i = 0; i < numberOfDataBits+degreeOfPolynomial; ++i) {
            data[i]=0;
            dividend[i]=0;
        }
        printf("Please enter the data bits from left to right including the CRC bits\n");
        for (int i = 0; i < numberOfDataBits; ++i) {
            printf("Please enter the bit\n");
            scanf("%d",&data[i]);
            dividend[i]=data[i];
        }
        int first1 = 0;
        while(1){
            first1=0;
            while(first1<numberOfDataBits+degreeOfPolynomial){
                if(dividend[first1]==1)
                    break;
                else
                    first1++;
            }
            if(numberOfDataBits+degreeOfPolynomial-first1<=degreeOfPolynomial){
                for (int i = first1; i < numberOfDataBits+degreeOfPolynomial; ++i) {
                    data[i]=dividend[i];
                }
                break;
            }
            else{
                for (int i = first1; i < first1+degreeOfPolynomial+1 ; ++i) {
                    if(dividend[i]!=coefficientsArr[i-first1]){
                        dividend[i]=1;
                    }
                    else
                        dividend[i]=0;
                }
            }
        }
        if(first1==numberOfDataBits+degreeOfPolynomial){
            printf("Accepted\n");
            printf("The required DataBits Are\n");
            for(int i = 0; i < numberOfDataBits-degreeOfPolynomial; ++i) {
                printf("%d",data[i]);
            }
        }
        else{
            printf("rejected");
        }
        printf("\n");

    }
    else{
        printf("invalid menu option selected\n");
    }
}



