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
    char * cur = sharedMemory;
    for (int i = 0; i < 100; ++i) {
        *cur = 'a';
        cur++;
    }
    *cur=',';
    //checking for memory overwriting
    cur=sharedMemory;
    while (1)
        if(*cur!='a')
            break;
    //printing data
    while (1){
        if(*cur==','){
            break;
        }
        putchar(*cur);
        cur++;
    }
    exit(0);
}