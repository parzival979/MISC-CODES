#include <iostream>
using namespace std;

struct linkedListNode* addNode(struct linkedListNode *head,int job,int priority,int time);
struct linkedListNode
{
    int jobNumber;
    int priority;
    int timeRequired;
    struct linkedListNode *nextNode;
};

int main(void)
{
    int job=1;
    struct linkedListNode *head = NULL;
    while(true)
    {
        int menu;
        cout << "PLEASE ENTER 1 TO ENTER A NEW JOB OR 0 TO EXIT\n";
        cin >> menu;
        if (menu == 1)
        {
            int priority, time,timeSub;
            cout << "PLEASE ENTER THE PRIORITY OF THE JOB\n";
            cin >> priority;
            cout << "PLEASE ENTER THE TIME OF THE JOB\n";
            cin >> time;
            cout << "PLEASE ENTER THE TIME SUBMITTED OF THE JOB\n";
            cin >> timeSub;
            struct linkedListNode* currentPtr = head;
            struct linkedListNode* prevPtr=NULL;
            bool added = false;
            int timeline=0;
            if(head == NULL){
                head = addNode(head,job,priority,time);
            }
            else {
                while (currentPtr != NULL) {
                    if (timeline + currentPtr->timeRequired >= timeSub) {
                        head = addNode(currentPtr, job, priority, time);
                        added = true;
                    } else {
                        timeline += currentPtr->timeRequired;
                        prevPtr=currentPtr;
                        currentPtr = currentPtr->nextNode;
                    }
                }
                if(currentPtr == NULL && !added){
                    prevPtr->nextNode= addNode(currentPtr,job,priority,time);
                }
            }
            //head = addNode(head, job, priority, time);
            job += 1;
        }
        else if (menu == 0)
        {
            break;
        }
        else
        {
            cout << "PLEASE ENTER THE CORRECT OPTION\n";
        }
    }
    int timeline=0;
    cout<<"THE COMPLETION TIME LINES ARE\n";
    while(head!=NULL)
    {
        struct linkedListNode* rmPtr=head;
        head=head->nextNode;
        cout<<"JOB NO:"<<rmPtr->jobNumber<<" TIMELINE:"<<timeline+1<<"-"<<timeline+rmPtr->timeRequired<<"\n";
        timeline+=rmPtr->timeRequired;
        delete rmPtr;
    }
}

struct linkedListNode* addNode(struct linkedListNode *head,int job,int priority,int time)
{
    linkedListNode *temp=new struct linkedListNode;
    temp->jobNumber=job;
    temp->priority=priority;
    temp->timeRequired=time;
    if(head==NULL)
    {
        temp->nextNode=NULL;
        return temp;
    }
    else
    {
        struct linkedListNode *currentNode=head,*prevNode=NULL;
        if(temp->priority<currentNode->priority)
        {
            temp->nextNode=head;
            return temp;
        }
        else if(temp->priority==currentNode->priority)
        {
            if(temp->timeRequired>currentNode->timeRequired)
            {
                temp->nextNode=currentNode;
                return temp;
            }
            else
            {
                while(currentNode->timeRequired>temp->timeRequired)
                {
                    prevNode=currentNode;
                    currentNode=currentNode->nextNode;
                    if(!currentNode || temp->priority!=currentNode->priority )
                    {
                        break;
                    }
                }
                prevNode->nextNode=temp;
                temp->nextNode=currentNode;
                return head;
            }

        }
        else if(temp->priority>currentNode->priority)
        {
            while (currentNode->priority!=temp->priority)
            {
                prevNode=currentNode;
                currentNode=currentNode->nextNode;
                if(!currentNode)
                {
                    break;
                }
            }
            if(currentNode==NULL)
            {
                prevNode->nextNode=temp;
                temp->nextNode=currentNode;
                return head;
            }
            else
            {
                while(currentNode->timeRequired>temp->timeRequired)
                {
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