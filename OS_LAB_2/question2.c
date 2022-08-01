#include <stdio.h>
struct inputDetails{
    int pid;
    int arrivalTime;
    int burstTime;
};
struct outputDetails{
    int completionTime;
    int waitingTime;
    int turnAroundTime;
};
int main() {
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
    }
    for (int i = 0; i < numProcesses; ++i) {
        for (int j = 0; j < numProcesses-i-1; ++j) {
            if(inputProcesses[j].arrivalTime>inputProcesses[j+1].arrivalTime && inputProcesses[j].pid>inputProcesses[j
                                                                                                                     +1].pid){
                int pid,at,bt;
                pid = inputProcesses[j].pid;
                at = inputProcesses[j].arrivalTime;
                bt = inputProcesses[j].burstTime;
                inputProcesses[j].pid=inputProcesses[j+1].pid;
                inputProcesses[j].arrivalTime=inputProcesses[j+1].arrivalTime;
                inputProcesses[j].burstTime=inputProcesses[j+1].burstTime;
                inputProcesses[j+1].pid=pid;
                inputProcesses[j+1].arrivalTime=at;
                inputProcesses[j+1].burstTime=bt;
            }
        }
    }
    struct outputDetails outputProcesses[numProcesses];
    int sumWT=0,sumTCT=0;
    int prevProcessTime = 0;
    for (int i = 0; i < numProcesses; ++i) {
        if(inputProcesses[i].arrivalTime<=prevProcessTime){
            outputProcesses[i].completionTime = prevProcessTime+inputProcesses[i].burstTime;
            outputProcesses[i].turnAroundTime = outputProcesses[i].completionTime-inputProcesses[i].arrivalTime;
            outputProcesses[i].waitingTime = outputProcesses[i].turnAroundTime - inputProcesses[i].burstTime;
            prevProcessTime = outputProcesses[i].completionTime;
        }
        else{
            outputProcesses[i].completionTime = inputProcesses[i].arrivalTime+inputProcesses[i].burstTime;
            outputProcesses[i].turnAroundTime = outputProcesses[i].completionTime-inputProcesses[i].arrivalTime;
            outputProcesses[i].waitingTime = outputProcesses[i].turnAroundTime - inputProcesses[i].burstTime;
            prevProcessTime = outputProcesses[i].completionTime;
        }
        sumWT+=outputProcesses[i].waitingTime;
        sumTCT+=outputProcesses[i].turnAroundTime;
    }
    printf("PID AT BT CT WT TCT\n");
    for (int i = 0; i < numProcesses; ++i) {
        printf("%d %d %d %d %d %d\n",inputProcesses[i].pid,inputProcesses[i].arrivalTime,inputProcesses[i].burstTime,outputProcesses[i].completionTime,outputProcesses[i].waitingTime,outputProcesses[i].turnAroundTime);
    }
    printf("Average WT %f\n",(double)sumWT/(double)numProcesses);
    printf("Average WT %f\n",(double)sumTCT/(double)numProcesses);
}