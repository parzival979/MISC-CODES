//Program By Sravanth Chowdary Potluri CS20B1006
#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

sem_t mutex,full,empty;
int buffer[1000],back=0;

void produce_item(int x)
{
    buffer[x]=rand()%100;
    printf("%i is produced\n",buffer[x]);
}

void consume_item(int x)
{
    printf("%i is consumed\n",buffer[x-1]);
}

void *producer(void *t)
{
    while(t)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        produce_item(back);
        back++;
        t--;
        sem_post(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *t)
{
    while(t)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        consume_item(back);
        back--;
        t--;
        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main()
{
    srand(time(0));
    int n,t;
    printf("enter maximum size of buffer: ");
    scanf("%i",&n);
    printf("enter number of items to be produced: ");
    scanf("%i",&t);
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,n);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,producer,(void*)t);
    pthread_create(&t2,NULL,consumer,(void*)t);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
}