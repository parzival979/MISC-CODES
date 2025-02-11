#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int PID,AT,BT,CT,waitingTime, turnAroundTime;
} process;

int compare(const void* a, const void* b){
    process *p = (process*) a;
    process *q = (process*) b;
    return (p->AT - q->AT);
}

int comparator(const void* a, const void* b){
    process *p = (process*) a;
    process *q = (process*) b;
    if(p->BT != q->BT)return (p->BT - q->BT);
    else return (p->PID - q->PID);
}

int main(){
    int numberOfP;
    double averageWaitingTime = 0, averageTurnAroundTime = 0;
    printf("Please enter the number of P: \n");
    scanf("%d", &numberOfP);
    process P[numberOfP];
    char choice;
    printf("(a)All arriving at Time 0\n(b)All arrive at different time\nPlease Enter your choice: \n");
    scanf(" %c", &choice);
    for(int i = 0; i < numberOfP;i++){
        printf("Please Enter the process id, arrival time and burst time of the Process %d: \n", i+1);
        scanf(" %d %d %d", &P[i].PID, &P[i].AT, &P[i].BT);
    }
    qsort((void*) P,numberOfP, sizeof(P[0]),compare);
    if(choice == 'a'){
        P[0].CT = P[0].BT;
        for(int i = 1; i < numberOfP;i++){
            P[i].CT = (P[i-1].CT + P[i].BT);
        }
        for(int i = 0; i < numberOfP;i++){
            P[i].turnAroundTime = (P[i].CT - P[i].AT);
            averageTurnAroundTime += P[i].turnAroundTime;
        }
        for(int i = 0; i < numberOfP;i++){
            P[i].waitingTime = (P[i].turnAroundTime - P[i].BT);
            averageWaitingTime += P[i].waitingTime;
        }
        averageTurnAroundTime /= numberOfP;
        averageWaitingTime /= numberOfP;
        printf("Process ID \t Arrival Time \t Burst Time \t Completion Time \t Waiting Time \t Turn Around Time \n");
        for(int i = 0; i <numberOfP;i++){
            printf("%d \t %d \t %d \t %d \t %d \t %d \n", P[i].PID,P[i].AT,P[i].BT,P[i].CT,P[i].waitingTime,P[i].turnAroundTime);
            printf("The average Waiting Time is %lf \n", averageWaitingTime);
            printf("The average Turn Around Time is %lf \n", averageTurnAroundTime);
        }
    }
    else if(choice == 'b'){
        bool visited[numberOfP];
        for(int i = 0; i < numberOfP;i++) visited[i] = false;
        P[0].CT = P[0].AT + P[0].BT;
        visited[0] = true;
        int counter = 0, i = 1, index = 0,j,done = 1, l;
        bool flag = false;
        while(done < numberOfP){
            if(!flag) l = P[index].CT;
            counter = 0;
            while(i < numberOfP && P[i].AT <= l){
                if(visited[i] == false){
                    counter++;
                }
                i++;
            }
            process temp[counter];
            i = 1, j = 0;
            while(i < numberOfP && P[i].AT <= l){
                if(visited[i] == false){
                    temp[j] = P[i];
                    j++;
                }
                i++;
            }
            qsort((void*) temp,counter, sizeof(temp[0]),comparator);
            int k = 0;
            while(k < numberOfP){
                if(temp[0].PID == P[k].PID){
                    visited[k] = true;
                    P[k].CT = l + P[k].BT;
                    done++;
                    index = k;
                    flag = false;
                    break;
                }
                k++;
            }
            i = 1;
            if(l == P[index].CT){
                l++;
                flag = true;
            }
        }
        for(int i = 0; i < numberOfP;i++){
            P[i].turnAroundTime = (P[i].CT - P[i].AT);
            averageTurnAroundTime += P[i].turnAroundTime;
        }
        for(int i = 0; i < numberOfP;i++){
            P[i].waitingTime = (P[i].turnAroundTime - P[i].BT);
            averageWaitingTime += P[i].waitingTime;
        }
        averageTurnAroundTime /= numberOfP;
        averageWaitingTime /= numberOfP;
        printf("Process ID \t Arrival Time \t Burst Time \t Completion Time \t Waiting Time \t Turn Around Time \n");
        for(int i = 0; i <numberOfP;i++){
            printf("%d \t %d \t %d \t %d \t %d \t %d \n", P[i].PID,P[i].AT,P[i].BT,P[i].CT,P[i].waitingTime,P[i].turnAroundTime);
        }
        printf("The average Waiting Time is %lf \n", averageWaitingTime);
        printf("The average Turn Around Time is %lf \n", averageTurnAroundTime);
    }
    else{
        printf("You've entered the wrong choice. Try again\n");
    }
    return 0;
}