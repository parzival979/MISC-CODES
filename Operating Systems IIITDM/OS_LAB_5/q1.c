//Program by Sravanth Chowdary Potluri CS20B1006

//Pre-procesor directives
#include <stdio.h>
#include <unistd.h>

//main function
int main(void){
    printf("Please enter n\n");
    int n;
    scanf("%d",&n);
    //forking
    int process = fork();
    int sum = 0;
    //conditionals for parent and child
    if(process>0){
        //parent loop
        //looping and adding even numbers
        for (int i = 1; i <= n ; ++i) {
            if(i%2==0)
                sum+=i;
        }
        //printing the result
        printf("The sum of even numbers until n is %d\n",sum);
        printf("The parent process pid is %d\n",getpid());
    }
    else if(process==0){
        //child loop
        //looping and adding even numbers
        for (int i = 1; i <= n ; ++i) {
            if(i%2==1)
                sum+=i;
        }
        //printing the result
        printf("The sum of odd numbers until n is %d\n",sum);
        printf("The child process pid is %d\n",getpid());
    }
}