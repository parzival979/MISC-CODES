//programmed by Sravanth Chowdary Potluri CS20B1006

//including required libraries
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    //creating the required pipe descriptors
    int pipDes1[2];

    //checking for pipe creation success
    int returnStatus1 = pipe(pipDes1);
    if(returnStatus1==-1){
        printf("Pipe Creation failed");
        return 1;
    }

    //taking input of the string to be reversed
    printf("Please enter the string 1\n");
    char reqString[100];
    fgets(reqString,100,stdin);
    //forking

    int forkVal=fork();
    //parent process conditional
    if(forkVal!=0){
        //closing the unnecessary pipe ends
        printf("The PPID of the main process is %d\n",getppid());
        close(pipDes1[0]);
        //writing input
        write(pipDes1[1],reqString, sizeof(reqString));
        wait(NULL);
    }
        //child process conditional
    else{
        printf("The PPID of the child process is %d\n",getppid());
        //closing the unnecessary pipe ends
        close(pipDes1[1]);
        //reading from the pipe
        char readMessage1[100];
        read(pipDes1[0],readMessage1,sizeof(readMessage1));
        int pipDes2[2];
        int returnStatus2 = pipe(pipDes2);
        if(returnStatus2==-1){
            printf("Pipe Creation failed");
            return 1;
        }
        int forkVal2=fork();
        //child process as parent
        if(forkVal2!=0){
            wait(NULL);
            char readMessage2[100];
            read(pipDes2[0],readMessage2,sizeof(readMessage2));
            printf("The length difference between the two messages is %d", strlen(readMessage1)- strlen(readMessage2));
        }
            //grandchild process
        else{
            printf("The PPID of the grand child process is %d\n",getppid());
            //closing the unnecessary pipe ends
            close(pipDes2[0]);
            char reqString2[100];
            printf("Please enter the string 2\n");
            fgets(reqString2,100,stdin);
            //writing input
            write(pipDes2[1],reqString2, sizeof(reqString2));
            exit(0);
        }
    }

}