// Including the required libraries
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main(){
    //key for the shared memory
    key_t req_key = 2997;
    //creating the memory of 250 bytes
    int memId = shmget(req_key,250,IPC_CREAT|0666);
    //error message
    if(memId<0){
        printf("Error in shared memory creation\n");
        exit(1);
    }
    //pointer for shared memory
    char * sharedMemory = shmat(memId,NULL,0);
    //writing data
    char reqString[50];
    printf("Please enter the required string\n");
    scanf("%s",reqString);
    char * curString = reqString;
    char * cur = sharedMemory;
    //writing the string in the memory
    while(1){
        if(*curString=='\0')
            break;
        *cur = *curString;
        cur++;
        curString++;
    }
    *cur=';';
    //checking for memory overwriting
    cur=sharedMemory;
    while (1)
        if(*cur=='\0')
            break;
    cur++;
    //printing the required result
    if(*cur=='1'){
        printf("The given string is a palindrome\n");
    }
    else if(*cur=='0'){
        printf("The given string is not a palindrome\n");
    }
    exit(0);
}