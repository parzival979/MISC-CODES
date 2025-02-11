#include<iostream>
//INCLUDING THE HEADER FILE
#include "queue.hpp"
//MAIN FUNCTION
int main(void){
    //CREATING THE OBJECT FOR THE REQUIRED FILE
queue requiredQueue;
//BOOLEAN TO CHECK THE CONTINUITY FOR THE MENU DRIVEN PROGRAM
bool programContinuity= true;
//LOOP FOR THE MENU
while(programContinuity){
    //PRINTING THE MENU
    std::cout<<"THE MENU IS\n";
    std::cout<<"1.ADD TO PRINT QUEUE\n";
    std::cout<<"2.CURRENT JOB\n";
    std::cout<<"3.EXECUTE A JOB\n";
    std::cout<<"4.DISPLAY JOBS\n";
    std::cout<<"5.EXIT\n";
    std::cout<<"PLEASE ENTER THE MENU NUMBER\n";
    //TAKING INPUT FOR THE MENU OPTION
    int menuOption;
    std::cin>>menuOption;
    //MENU OPTIONS 1 TO 4
    if(menuOption<=4 && menuOption>=1){
        //MENU OPTION TO TAKE A JOB INTO THE QUEUE
        if(menuOption==1){
            if(requiredQueue.isFull())
                std::cout<<"THE QUEUE IS FULL\n";
            else{
                std::cout<<"PLEASE ENTER THE JOB ID\n";
                int jobId;
                std::cin>>jobId;
                requiredQueue.enQueue(jobId);
            }
        }
        //MENU OPTION TO PRINT THE NEXT JOB THAT WILL BE EXECUTED NEXT
        else if(menuOption==2){
            if(requiredQueue.isEmpty())
                std::cout<<"THE QUEUE IS EMPTY\n";
            else
                std::cout<<"THE NEXT JOB THAT WILL BE EXECUTED IS "<< requiredQueue.peek()<<"\n";
        }
        //MENU OPTION TO COMPLETE A JOB
        else if(menuOption==3){
            if(requiredQueue.isEmpty())
                std::cout<<"THE QUEUE IS EMPTY\n";
            else
                std::cout<<"THE JOB " << requiredQueue.deQueue() << " HAS BEEN COMPLETED\n";
        }
        // MENU OPTION TO PRINT OUT THE PENDING JOBS
        else if(menuOption==4){
            if(requiredQueue.isEmpty())
                std::cout<<"THE QUEUE IS EMPTY\n";
            else{
                std::cout<<"THE PENDING JOBS ARE\n";
                requiredQueue.display();
            }

        }

    }
    //MENU OPTION TO EXIT THE PROGRAM
    else if (menuOption==5){
        programContinuity= false;
    }
    //DEFAULT MENU OPTION
    else{
        std::cout<<"PLEASE ENTER THE CORRECT OPTION\n";
    }

}

}
