//Program By Sravanth Chowdary Potluri CS20B1006
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* reverse(char *buffer, int i, int j);
void add(char msg[],char temp[],int n,int m);
void swap(char *x, char *y);
char* itoa(int value, char* buffer, int base);
void Sender(char *reqBinary,char* answer,int size_of_string);
void Receiver(char *reqBinary,char* answer,int size_of_string);

void add(char msg[],char temp[],int n,int m)
{
    int i;
    char carry='0';
    for(i=m-1;i>=0;i--)
    {
        if(msg[n*m+i]=='0'&&temp[i]=='0')
        {
            temp[i]=carry;
            carry='0';
        }
        else if(msg[n*m+i]=='1'&&temp[i]=='1')
        {
            temp[i]=carry;
            carry='1';
        }
        else if(carry=='0') temp[i]='1';
        else temp[i]='0';
    }
    if(carry=='1'){
        for(i=m-1;temp[i]=='1';i--) temp[i]='0';
        temp[i]='1';
    }

}

// Function to swap two numbers
void swap(char *x, char *y) {
    char t = *x; *x = *y; *y = t;
}

// Function to reverse `buffer[i…j]`
char* reverse(char *buffer, int i, int j)
{
    while (i < j) {
        swap(&buffer[i++], &buffer[j--]);
    }

    return buffer;
}

char* itoa(int value, char* buffer, int base)
{
    // invalid input
    if (base < 2 || base > 32) {
        return buffer;
    }

    // consider the absolute value of the number
    int n = abs(value);

    int i = 0;
    while (n)
    {
        int r = n % base;

        if (r >= 10) {
            buffer[i++] = 65 + (r - 10);
        }
        else {
            buffer[i++] = 48 + r;
        }

        n = n / base;
    }

    // if the number is 0
    if (i == 0) {
        buffer[i++] = '0';
    }

    // If the base is 10 and the value is negative, the resulting string
    // is preceded with a minus sign (-)
    // With any other base, value is always considered unsigned
    if (value < 0 && base == 10) {
        buffer[i++] = '-';
    }

    buffer[i] = '\0'; // null terminate string

    // reverse the string and return it
    return reverse(buffer, 0, i-1);
}

int main() {
    printf("Please enter the required string to convert into binary and send\n");
    char reqString[100];
    scanf("%s",reqString);
    char reqBinary[800];
    int curStringPtr = 0;
    int curBinPtr=0;
    while (1){
        if(reqString[curStringPtr]=='\0')
            break;
        char curCharBinString[10];
        itoa(reqString[curStringPtr],curCharBinString,2);
        unsigned long string_size=strlen(curCharBinString);
        char finalString[10];
        int curFinalStringPtr;
        for (curFinalStringPtr = 0; curFinalStringPtr < 8-string_size; ++curFinalStringPtr) {
            finalString[curFinalStringPtr]='0';
        }
        int curPtr=0;
        while (1){
            if(curCharBinString[curPtr]=='\0'){
                finalString[curFinalStringPtr]=curCharBinString[curPtr];
                break;
            }
            finalString[curFinalStringPtr]=curCharBinString[curPtr];
            curFinalStringPtr++;
            curPtr++;
        }
        for (int i = 0; i < 10; ++i) {
            if(finalString[i]=='\0')
                break;
            reqBinary[curBinPtr]=finalString[i];
            curBinPtr++;
        }
        curStringPtr++;
    }
    reqBinary[curBinPtr]='\0';
    printf("The entered string in binary is\n");
    printf("%s\n",reqBinary);
    char answer[9];
    answer[8]='\0';
    Sender(reqBinary,answer, strlen(reqString));
    printf("The encoded checksum bits are\n");
    printf("%s\n",answer);
    Receiver(reqBinary,answer, strlen(reqString));
    printf("The Receiver Checking Bits are\n");
    printf("%s\n",answer);
    return 0;
}

void Sender(char *reqBinary,char* answer,int size_of_string){
    for (int i = 0; i < 8; ++i) {
        answer[i]='0';
    }
    for (int i = 0; i < size_of_string; ++i) {
        add(reqBinary,answer,i,8);
    }
    for (int i = 0; i < 8; ++i) {
        if(answer[i]=='1')
            answer[i]='0';
        else if(answer[i]=='0')
            answer[i]='1';
    }

}

void Receiver(char *reqBinary,char* answer,int size_of_string){
    for (int i = 0; i < size_of_string; ++i) {
        add(reqBinary,answer,i,8);
    }
    for (int i = 0; i < 8; ++i) {
        if(answer[i]=='1')
            answer[i]='0';
        else if(answer[i]=='0')
            answer[i]='1';
    }
}

