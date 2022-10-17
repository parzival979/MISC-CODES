//Program By Sravanth Chowdary Potluri CS20B1006
#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

int turn1=1,turn2=1,flag;

void *thread_fna(void *arg)
{
    int t=1;
    while(t--)
    {
        turn1=1;
        flag=2;
        while(turn2==1&&flag==2);
        printf("statement A1\n");
        turn1=0;
        turn1=1;
        flag=2;
        while(turn2==1&&flag==2);
        printf("statement A2\n");
        turn1=0;
    }
}

void *thread_fnb(void *arg)
{
    int t=1;
    while(t--)
    {
        turn2=1;
        flag=1;
        while(turn1==1&&flag==1);
        printf("statement B1\n");
        turn2=0;
        turn2=1;
        flag=1;
        while(turn1==1&&flag==1);
        printf("statement B2\n");
        turn2=0;
    }
}

int main()
{
    pthread_t t1,t2;
    pthread_create(&t1,NULL,thread_fna,NULL);
    pthread_create(&t2,NULL,thread_fnb,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
}