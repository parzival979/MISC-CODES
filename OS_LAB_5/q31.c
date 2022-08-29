//Program by Sravanth Chowdary Potluri CS20B1006

//Pre-processor directives
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

// main function
int main(){
    printf("Hello i am program 1\n");
    //using exec function
    char *args[]={"./exec2",NULL};
    execvp(args[0],args);
}