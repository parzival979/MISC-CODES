//including the required libraries
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main(){
    //key for shared memory
    key_t req_key = 2997;
    //getting memory id
    int memId = shmget(req_key,250,0666);
    //error message
    if(memId<0){
        printf("Error in shared memory creation\n");
        exit(1);
    }
    //required pointers
    char * sharedMemory = shmat(memId,NULL,0);
    char * cur = sharedMemory;
    while (1){
        if(*cur==','){
            break;
        }
        putchar(*cur);
        cur++;
    }
    //overwriting the memory
    cur = sharedMemory;
    for (int i = 0; i < 100; ++i) {
        *cur = 'b';
        cur++;
    }
    *cur=',';
    exit(0);
}