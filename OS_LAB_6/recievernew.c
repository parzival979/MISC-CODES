//including the required libraries
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
int isPalindrome(char str[]);
int main(){
    //key for shared memory
    key_t req_key = 2997;
    //getting memory id
    int memId = shmget(req_key,250,0666);
    //error message
    if(memId<0){
        printf("Error in shared memory\n");
        exit(1);
    }
    //required pointers
    char * sharedMemory = shmat(memId,NULL,0);
    char * cur = sharedMemory;
    char reqString[50];
    char * curString = reqString;
    //copying the string from the memory
    while (1){
        if(*cur==';'){
            break;
        }
        *curString=*cur;
        curString++;
        cur++;
    }
    //putting null character at last
    *curString='\0';
    printf("%s\n",reqString);
    char result = isPalindrome(reqString);
    //overwriting the memory with the result
    cur = sharedMemory;
    *cur='\0';
    cur++;
    *cur=result;
    cur++;
    *cur='\0';
    exit(0);
}

//is palindrome function
int isPalindrome(char str[])
{
    // Start from leftmost and
    // rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;

    // Keep comparing characters
    // while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            return '0';
        }
    }
    return '1';
}