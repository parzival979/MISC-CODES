#include <iostream>

struct linkedListNode* addNode(struct linkedListNode *head,int job,int priority,int time);
struct linkedListNode{
    int jobNumber;
    int priority;
    int timeRequired;
    struct linkedListNode *nextNode;
};

int main(void){
    int job=1;
    struct linkedListNode *head = NULL;
    while(true){
        int menu;
        std::cout << "PLEASE ENTER 1 TO ENTER A NEW JOB OR 0 TO EXIT\n";
        std::cin >> menu;
        if (menu == 1) {
            int priority, time;
            std::cout << "PLEASE ENTER THE PRIORITY OF THE JOB\n";
            std::cin >> priority;
            std::cout << "PLEASE ENTER THE TIME OF THE JOB\n";
            std::cin >> time;
            head = addNode(head, job, priority, time);
            job += 1;
        } else if (menu == 0) {
            break;
        } else {
            std::cout << "PLEASE ENTER THE CORRECT OPTION\n";
        }
    }
    int timeline=0;
    std::cout<<"THE COMPLETION TIME LINES ARE\n";
    while(head!=NULL){
        struct linkedListNode* rmPtr=head;
        head=head->nextNode;
        std::cout<<"JOB NO:"<<rmPtr->jobNumber<<" TIMELINE:"<<timeline+1<<"-"<<timeline+rmPtr->timeRequired<<"\n";
        timeline+=rmPtr->timeRequired;
        delete rmPtr;
    }




}

struct linkedListNode* addNode(struct linkedListNode *head,int job,int priority,int time){
    linkedListNode *temp=new struct linkedListNode;
    temp->jobNumber=job;
    temp->priority=priority;
    temp->timeRequired=time;
    if(head==NULL){
        temp->nextNode=NULL;
        return temp;
    }
    else{
        struct linkedListNode *currentNode=head,*prevNode=NULL;
        if(temp->priority<currentNode->priority){
            temp->nextNode=head;
            return temp;
        }
        else if(temp->priority==currentNode->priority){
            if(temp->timeRequired>currentNode->timeRequired){
                temp->nextNode=currentNode;
                return temp;
            }
            else{
                while(currentNode->timeRequired>temp->timeRequired){
                    prevNode=currentNode;
                    currentNode=currentNode->nextNode;
                    if(!currentNode || temp->priority!=currentNode->priority ){
                        break;
                    }
                }
                prevNode->nextNode=temp;
                temp->nextNode=currentNode;
                return head;
            }

        }
        else if(temp->priority>currentNode->priority){
            while (currentNode->priority!=temp->priority){
                prevNode=currentNode;
                currentNode=currentNode->nextNode;
                if(!currentNode){
                    break;
                }
            }
            if(currentNode==NULL){
                prevNode->nextNode=temp;
                temp->nextNode=currentNode;
                return head;
            }
            else{
                while(currentNode->timeRequired>temp->timeRequired){
                    prevNode=currentNode;
                    currentNode=currentNode->nextNode;
                    if(!currentNode || temp->priority!=currentNode->priority){
                        break;
                    }
                }
                prevNode->nextNode=temp;
                temp->nextNode=currentNode;
                return head;
            }
            }
        return head;
        }

}

