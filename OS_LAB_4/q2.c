#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int pid;
    if((pid = fork())){
        printf("the pid from fork is %d\n",pid);
        printf("The pid from get pid is %d\n",getpid());
        if((pid = fork())){
            printf("the pid from fork is %d\n",pid);
            printf("The pid from get pid is %d\n",getpid());
            if((pid = fork())){
                printf("the pid from fork is %d\n",pid);
                printf("The pid from get pid is %d\n",getpid());
            }
            else{
                printf("the pid from fork is %d\n",pid);
                printf("The pid from get pid is %d\n",getpid());
            }
        }
        else{
            printf("the pid from fork is %d\n",pid);
            printf("The pid from get pid is %d\n",getpid());
            if((pid = fork())){
                printf("the pid from fork is %d\n",pid);
                printf("The pid from get pid is %d\n",getpid());
            }
            else{
                printf("the pid from fork is %d\n",pid);
                printf("The pid from get pid is %d\n",getpid());
            }
        }
    }
    else{
        printf("the pid from fork is %d\n",pid);
        printf("The pid from get pid is %d\n",getpid());
        if((pid = fork())){
            printf("the pid from fork is %d\n",pid);
            printf("The pid from get pid is %d\n",getpid());
            if((pid = fork())){
                printf("the pid from fork is %d\n",pid);
                printf("The pid from get pid is %d\n",getpid());
            }
            else{
                printf("the pid from fork is %d\n",pid);
                printf("The pid from get pid is %d\n",getpid());
            }
        }
        else{
            printf("the pid from fork is %d\n",pid);
            printf("The pid from get pid is %d\n",getpid());
            if((pid = fork())){
                printf("the pid from fork is %d\n",pid);
                printf("The pid from get pid is %d\n",getpid());
            }
            else{
                printf("the pid from fork is %d\n",pid);
                printf("The pid from get pid is %d\n",getpid());
            }
        }
    }
}