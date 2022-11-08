//Programmed By Sravanth Chowdary Potluri CS20B1006
#include<stdio.h>
#include<stdlib.h>

//function to print the matrix
void printMatrix(int a[6][4])
{
    int i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<4;j++)
            printf("%i ",a[i][j]);
        printf("\n");
    }
}

//function to print the available array
void printAvailable(int a[4])
{
    int i;
    for(i=0;i<4;i++)
        printf("%i ",a[i]);
    printf("\n");
}

//Defining The Required Matrix Structures
int allocation[6][4],max[6][4],need[6][4],available[4];

//Function To check for the safe state
int safety()
{
    int work[4],i,finish[6]={0,0,0,0,0,0},sequence[6],count=0;
    for(i=0;i<4;i++) work[i]=available[i];
    for(i=0;i<6;i++)
        if(finish[i]==0&&need[i][0]<=work[0]&&need[i][1]<=work[1]&&need[i][2]<=work[2]&&need[i][3]<=work[3])
        {
            work[0]+=allocation[i][0];
            work[1]+=allocation[i][1];
            work[2]+=allocation[i][2];
            work[3]+=allocation[i][3];
            finish[i]=1;
            sequence[count++]=i;
            i=-1;
        }
    for(i=0;i<6;i++)
        if(finish[i]==0) return 0;
    printf("safe sequence is ");
    for(i=0;i<6;i++)
        printf("%i ",sequence[i]);
    printf("\n");
    return 1;
}

//main driver function
int main()
{
    int i,j,a[4];
    for(i=0;i<6;i++)
    {
        printf("enter instances allocated to process %i for resources A,B,C,D: ",i);
        scanf("%i %i %i %i",&allocation[i][0],&allocation[i][1],&allocation[i][2],&allocation[i][3]);
    }
    for(i=0;i<6;i++)
    {
        printf("enter maximum number of instances required by process %i for resouces A,B,C,D: ",i);
        scanf("%i %i %i %i",&max[i][0],&max[i][1],&max[i][2],&max[i][3]);
    }
    printf("enter available instances of resources A,B,C,D: ");
    scanf("%i %i %i %i",&available[0],&available[1],&available[2],&available[3]);
    for(i=0;i<6;i++)
        for(j=0;j<4;j++)
            if(max[i][j]<allocation[i][j])
            {
                printf("allocated more than required");
                exit(0);
            }
            else need[i][j]=max[i][j]-allocation[i][j];
    if(!safety())
    {
        printf("there is possibility of deadlock");
        exit(0);
    }
    while(1)
    {
        printf("enter 1 to make request\nenter 2 to exit\n");
        scanf("%i",&j);
        if(j==1)
        {
            printf("enter process number: ");
            scanf("%i",&j);
            if(j<0||j>5)
            {
                printf("invalid process number\n");
                continue;
            }
            printf("enter instances required for resources A,B,C,D: ");
            scanf("%i %i %i %i",&a[0],&a[1],&a[2],&a[3]);
            if(a[0]>need[j][0]||a[1]>need[j][1]||a[2]>need[j][2]||a[3]>need[j][3]) printf("requested more than required\n");
            else if(a[0]>available[0]||a[1]>available[1]||a[2]>available[2]||a[3]>available[3]) printf("request rejected\n");
            else
            {
                for(i=0;i<4;i++)
                {
                    allocation[j][i]+=a[i];
                    need[j][i]-=a[i];
                    available[i]-=a[i];
                }
                if(safety())
                {
                    printf("request granted\n");
                    if(need[j][0]==0&&need[j][1]==0&&need[j][2]==0&&need[j][3]==0)
                        for(i=0;i<4;i++)
                        {
                            available[i]+=allocation[j][i];
                            allocation[j][i]=0;
                        }
                    printf("The Required Allocation Matrix is\n");
                    printMatrix(allocation);
                    printf("The Required Max Matrix is\n");
                    printMatrix(max);
                    printf("The Required Need Matrix is\n");
                    printMatrix(need);
                    printf("The Required Available Array is\n");
                    printAvailable(available);
                }
                else
                {
                    printf("request rejected\n");
                    for(i=0;i<4;i++)
                    //reverting the changes if the request is rejected
                    {
                        allocation[j][i]-=a[i];
                        need[j][i]+=a[i];
                        available[i]+=a[i];
                    }
                }
            }
        }
        else if(j==2) break;
        else printf("invalid option entered\n");
    }
}

