//Programmed By Sravanth Chowdary Potluri CS20B1006
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// The function to be executed by all threads
void *printingThread(void *vargp)
{
    // Store the value argument passed to this thread
    int final_number = (int) vargp;
    printf("The requested numbers are\n");
    //Printing The Required Numbers
    for (int i = 0; i <= final_number; ++i) {
        printf("%d\n",i);
    }
}

int main()
{
    int i;
    pthread_t tid;
    //Taking The Required Integer As Input
    printf("Please enter the number until which you want the numbers to be printed upto\n");
    scanf("%d",&i);
    //Creating The Thread
    pthread_create(&tid, NULL,&printingThread, (void *)i);
    pthread_join(tid,NULL);
    pthread_exit(NULL);


}
