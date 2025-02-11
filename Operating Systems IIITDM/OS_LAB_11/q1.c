//Programmed By Sravanth Chowdary Potluri CS20B1006

//Including the required libraries
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

//required variables
sem_t wrt,mutex;
int readcount=0,data=10;

//functions to execute read and write
void read(int t)
{
    printf("reader %i reads %i\n",t,data);
}

void write(int t)
{
    data+=10;
    printf("writer %d updates\n",t);
}

//reader and writer threads with s
void *reader(void *t)
{
    int n=5;
    while(n--)
    {
        sem_wait(&mutex);
        readcount++;
        if(readcount==1) sem_wait(&wrt);
        sem_post(&mutex);

        read((int)t);

        sem_wait(&mutex);
        readcount--;
        if(readcount==0) sem_post(&wrt);
        sem_post(&mutex);
    }
}

void *writer(void *t)
{
    int n=5;
    while(n--)
    {
        sem_wait(&wrt);

        write((int)t);

        sem_post(&wrt);
    }
}

//main function creating the threads and joining them
int main()
{
    sem_init(&wrt,0,1);
    sem_init(&mutex,0,1);
    pthread_t r1,r2,r3,w1,w2;
    pthread_create(&r1,NULL,reader,(void *)1);
    pthread_create(&r2,NULL,reader,(void *)2);
    pthread_create(&w1,NULL,writer,(void *)1);
    pthread_create(&w2,NULL,writer,(void *)2);
    pthread_create(&r3,NULL,reader,(void *)3);

    pthread_join(r1,NULL);
    pthread_join(r2,NULL);
    pthread_join(r3,NULL);
    pthread_join(w1,NULL);
    pthread_join(w2,NULL);

    sem_destroy(&wrt);
    sem_destroy(&mutex);
}