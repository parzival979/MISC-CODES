//Programmed By Sravanth Chowdary Potluri CS20B1006
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// The function to be executed by all threads
void *printingThread(void *vargp)
{
    // Store the value argument array passed to this thread
    int* req_array = (int*) vargp;
    int* sum=(int *) malloc(sizeof(int));
    //summing the required array
    for (int i = 0; i < 5; ++i) {
        *sum+=req_array[i];
    }
    pthread_exit((void *)sum);
}

int main()
{
    int i[5];
    pthread_t tid;
    int* result;
    for (int j = 0; j < 5; ++j) {
        printf("Please enter the 5 values for the array\n");
        scanf("%d",&i[j]);
    }
    //Taking The Required Integer As Input
    //Creating The Thread
    pthread_create(&tid, NULL,&printingThread, i);
    pthread_join(tid,(void *)&result);
    printf("The Sum is %d",*result);

}
