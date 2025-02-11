//Program by Sravanth Chowdary Potluri CS20B1006

//Pre-processor directives
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

// required comparator functions for qsort
int cmpfunc1 (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int cmpfunc2 (const void * a, const void * b) {
    return ( *(int*)b - *(int*)a );
}

//printing the required array
void printarr(int* arr,int n){
    printf("The array is\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//main function
int main(void){
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        printf("Please enter the number\n");
        scanf("%d",&arr[i]);
    }
    //forking
    int process = fork();
    //conditionals for parent and child
    if(process>0){
        //parent process
        //waiting for the child process to complete
        wait(NULL);
        //sorting
        qsort(arr, 10, sizeof(int), cmpfunc1);
        printf("The parent process pid is %d\n",getpid());
        //printing the array
        printarr(arr,10);
    }
    else if(process==0){
        //child process
        //sorting
        qsort(arr, 10, sizeof(int), cmpfunc2);
        printf("The child process pid is %d\n",getpid());
        //printing the array
        printarr(arr,10);
        exit(0);
    }
}