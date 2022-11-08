#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv) {
    FILE * reqFilePtr = NULL;
    reqFilePtr = fopen(argv[1],"r");
    FILE * outputFilePtr = NULL;
    outputFilePtr = fopen("output.c","w+");
    int prevChar = 0;
    int currentChar = fgetc(reqFilePtr);
    while (currentChar!=EOF){
        if(currentChar == '*' && prevChar == '/'){
            while(1){
                if(currentChar == '/' && prevChar == '*'){
                    break;
                }
                prevChar =currentChar;
                currentChar = fgetc(reqFilePtr);
            }
            prevChar =currentChar;
            currentChar = fgetc(reqFilePtr);
        }
        else if(currentChar == '/' && prevChar == '/'){
            while(1){
                if(currentChar == '\n'){
                    break;
                }
                prevChar =currentChar;
                currentChar = fgetc(reqFilePtr);
            }
            prevChar =currentChar;
            currentChar = fgetc(reqFilePtr);
        }
        else if(currentChar == ' ' && prevChar == ' '){
            prevChar =currentChar;
            currentChar = fgetc(reqFilePtr);
            continue;
        }
        else if(currentChar == '\n' && prevChar == '\n'){
            prevChar =currentChar;
            currentChar = fgetc(reqFilePtr);
            continue;
        }
        else{
            fputc(currentChar,outputFilePtr);
            prevChar =currentChar;
            currentChar = fgetc(reqFilePtr);
        }

    }
    printf("Output File Created");
    fclose(outputFilePtr);
    fclose(reqFilePtr);
}