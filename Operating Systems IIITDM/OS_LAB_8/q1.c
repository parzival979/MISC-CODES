//Programmed By Sravanth Chowdary Potluri CS20B1006
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Let us create a global variable to change it in threads
int sum[5] = {0};

// The function to be executed by all threads
void *summingThread(void *vargp)
{
    // Store the value argument passed to this thread
    int sumThreadNumber = (int)vargp;
    int initial = (sumThreadNumber * 200)+1;
    int final = initial+199;
    for (; initial <= final; ++initial) {
        sum[sumThreadNumber]+=initial;
    }

}

int main()
{
    int i;
    pthread_t tid[5];

    // Let us create five threads to pass required arguments to sum 200 numbers at once
    for (i = 0; i < 5; i++)
        pthread_create(&tid[i], NULL,&summingThread, (void *)i);
    for (i = 0; i < 5; i++)
        pthread_join(tid[i],NULL);

    //Printing the required sub sums
    printf("The Sum Of The Required Numbers is %d\n",sum[0]+sum[1]+sum[2]+sum[3]+sum[4]);
    pthread_exit(NULL);


}
