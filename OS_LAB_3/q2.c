#include <stdio.h>
struct inputDetails{
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int priority;
    int completionTime;
    int waitingTime;
    int turnAroundTime;
};

int main(){
    printf("Please enter the number of processes\n");
    int numProcesses;
    scanf("%d",&numProcesses);
    struct inputDetails inputProcesses[numProcesses];
    for (int i = 0; i < numProcesses ;++i) {
        printf("Please Enter the PID of the Process\n");
        scanf("%d",&inputProcesses[i].pid);
        printf("Please Enter the arrival time of the Process\n");
        scanf("%d",&inputProcesses[i].arrivalTime);
        printf("Please Enter the burst time of the Process\n");
        scanf("%d",&inputProcesses[i].burstTime);
        printf("Please Enter the priority of the Process\n");
        scanf("%d",&inputProcesses[i].priority);
        inputProcesses[i].remainingTime=inputProcesses[i].burstTime;
        inputProcesses[i].completionTime=0;
        inputProcesses[i].waitingTime=0;
        inputProcesses[i].turnAroundTime=0;
    }
    int currentProcessNum=0;
    int time  = 0;
    int highest_priority = 0;
    int numCompleted = 0;
    while(numCompleted<numProcesses){
        for (int i = 0; i < numProcesses; ++i) {
            if(time==inputProcesses[i].arrivalTime)
                for (int j = 0; j < numProcesses; ++j) {
                    if(inputProcesses[j].priority>highest_priority && inputProcesses[j].remainingTime!=0 && inputProcesses[j].arrivalTime<=time){
                        highest_priority = inputProcesses[j].priority;
                        currentProcessNum = j;
                    }
                }
        }
        inputProcesses[currentProcessNum].remainingTime--;
        if(inputProcesses[currentProcessNum].remainingTime == 0){
            inputProcesses[currentProcessNum].completionTime = time+1;
            numCompleted++;
        }
        time++;
    }
    int totalTAT = 0;
    int totalWT = 0;
    printf("The Required Details are\n");
    printf("pid at bt rt pri ct wt tat\n");
    for (int i = 0; i < numProcesses; ++i) {
        inputProcesses[i].turnAroundTime = inputProcesses[i].completionTime-inputProcesses[i].arrivalTime;
        inputProcesses[i].waitingTime = inputProcesses[i].turnAroundTime-inputProcesses[i].burstTime;
        totalTAT += inputProcesses[i].turnAroundTime;
        totalWT +=inputProcesses[i].waitingTime;
        printf("%d %d %d %d %d %d %d %d",inputProcesses[i].turnAroundTime,inputProcesses[i].arrivalTime,inputProcesses[i].burstTime,inputProcesses[i].remainingTime,inputProcesses[i].priority,inputProcesses[i].completionTime,inputProcesses[i].waitingTime,inputProcesses[i].turnAroundTime);
    }
    printf("Average WT %f\n",(double)totalWT/(double)numProcesses);
    printf("Average TAT %f\n",(double)totalTAT/(double)numProcesses);
}