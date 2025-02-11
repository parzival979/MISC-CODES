#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE * reqFilePtr = NULL;
    reqFilePtr = fopen("Input1.txt","r");
    FILE * outputFilePtr = fopen("output.txt","w+");
    int currentChar = fgetc(reqFilePtr);
    while(currentChar!=EOF){
        if(currentChar>=97 && currentChar<=122)
            printf("%c",currentChar-32);
        else if(currentChar>=65 && currentChar<=90)
            printf("%c",currentChar+32);
        else
            printf("%c",currentChar);
        currentChar = fgetc(reqFilePtr);
    }
    fclose(outputFilePtr);
    fclose(reqFilePtr);
}
