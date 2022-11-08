#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv) {
    FILE * reqFilePtr = NULL;
    reqFilePtr = fopen(argv[1],"r");
    int numLines = 0;
    int numChar = 0;
    int numSpaces = 0;
    int numNonEmptyLines = 0;
    int prevChar = 0;
    int currentChar = fgetc(reqFilePtr);
    while (currentChar!=EOF){
        if(currentChar == ' '){
            numChar++;
            numSpaces++;
        }
        else if(currentChar =='\n' && prevChar=='\n'){
            numLines++;
            numChar++;
        }
        else if(currentChar =='\n'){
            numSpaces++;
            numLines++;
            numChar++;
        }
        else{
            numChar++;
        }
        prevChar =currentChar;
        currentChar = fgetc(reqFilePtr);
    }
    printf("The number of lines is %d\nthe number of characters is %d\nthe number of words is %d\n",numLines,numChar,numSpaces);
    fclose(reqFilePtr);
}