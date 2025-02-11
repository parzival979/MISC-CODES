//programmed by Sravanth Chowdary Potluri CS20B1006

//including required libraries
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

//function to reverse the string
void revstr(char *str1);


int main() {
    //creating the required pipe descriptors
    int pipDes1[2],pipDes2[2];

    //checking for pipe creation success
    int returnStatus1 = pipe(pipDes1);
    if(returnStatus1==-1){
        printf("Pipe Creation failed");
        return 1;
    }
    int returnStatus2 = pipe(pipDes2);
    if(returnStatus2==-1){
        printf("Pipe Creation failed");
        return 1;
    }

    //taking input of the string to be reversed
    printf("Please enter the string to be reversed\n");
    char reqString[100];
    gets(reqString);
    //forking
    int forkVal=fork();
    //parent process conditional
    if(forkVal!=0){
        //closing the unnecessary pipe ends
        close(pipDes1[0]);
        close(pipDes2[1]);
        //writing input
        write(pipDes1[1],reqString, sizeof(reqString));\
        //waiting for the child to exit
        wait(NULL);
        char reversedString[100];
        //reading the reversed string and printing
        read(pipDes2[0],reversedString,sizeof(reversedString));
        printf("The Reversed String is %s",reversedString);
    }
        //child process conditional
    else{
        //closing the unnecessary pipe ends
        close(pipDes1[1]);
        close(pipDes2[0]);
        //reading from the pipe
        char readMessage[100];
        read(pipDes1[0],readMessage,sizeof(readMessage));
        //reversed the string
        revstr(readMessage);
        //written it back into pipe 2
        write(pipDes2[1],readMessage,sizeof (readMessage));
    }



}

void revstr(char *str1)
{
    // declare variable
    int i, len, temp;
    len = strlen(str1); // use strlen() to get the length of str string

    // use for loop to iterate the string
    for (i = 0; i < len/2; i++)
    {
        // temp variable use to temporary hold the string
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
}
