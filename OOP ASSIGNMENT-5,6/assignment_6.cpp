//INCLUDING THE C++ STANDARD LIBRARY
#include <iostream>
//CLASS FOR THE LINKED LIST NODES
class linkedListNode{


    //PRIVATE ACCESS SPECIFIER FOR DATA MEMBERS
private:
    int data;
    linkedListNode *nextNodePtr;


    //PUBLIC ACCESS SPECIFIER FOR THE METHODS
public:


    //METHOD TO SET DATA IN A NODE
    void setData(int data1){
        data=data1;
    }


    //METHOD TO GET DATA FROM A NODE
    int getData(){
        return data;
    }


    //METHOD TO SET THE NEXT NODE POINTER OF A GIVEN NODE
    void setPtr(linkedListNode *ptr){
        nextNodePtr=ptr;
    }


    //METHOD TO GET THE NEXT NODE OF A GIVEN POINTER
    linkedListNode* getPtr(){
        return nextNodePtr;
    }

};

//FUNCTION TO PRINT THE LINKED LIST
void printList(linkedListNode *head){
    if(head==NULL){
        std::cout<<"LIST EMPTY\n";
    }
    else {
        std::cout << "THE LIST IS\n";
        linkedListNode *currentNode = head;
        while (currentNode != NULL) {
            std::cout << currentNode->getData();
            currentNode = currentNode->getPtr();
            if (currentNode != NULL)
                std::cout << "->";
        }
        std::cout << "\n";
    }
}

//OVERLOADED FUNCTIONS TO INSERT NODE
linkedListNode* insertElement(linkedListNode* head,int data,int position){
    linkedListNode* currentNode=head;
    if (head==NULL){
        head = new linkedListNode;
        head->setData(data);
        head->setPtr(NULL);
        return head;
    }

    if(position<1){
        std::cout<<"POSITION DOES NOT EXIST\n";
        return head;
    }
    else if(position==1){
        head = new linkedListNode;
        head->setData(data);
        head->setPtr(currentNode);
        return head;
    }
    else{
        linkedListNode* prevPtr=currentNode;
        currentNode=currentNode->getPtr();
        for (int i = 2; i <=position ; ++i) {
            if(currentNode==NULL && i!=position){
                std::cout<<"POSITION DOES NOT EXIST\n";
                return head;
            }
            else if(currentNode==NULL && i==position){
                prevPtr->setPtr(new linkedListNode);
                prevPtr->getPtr()->setPtr(currentNode);
                prevPtr->getPtr()->setData(data);
                return head;
            }
            else if(i==position){
                prevPtr->setPtr(new linkedListNode);
                prevPtr->getPtr()->setPtr(currentNode);
                prevPtr->getPtr()->setData(data);
                return head;
            }
            else{
                prevPtr=currentNode;
                currentNode=currentNode->getPtr();
            }
        }
        return head;
    }
}

linkedListNode* insertElement(linkedListNode* head,int data){
    if(head==NULL){
        head = new linkedListNode;
        head->setData(data);
        head->setPtr(NULL);
        return head;
    }

    linkedListNode* currentNode=head;
    linkedListNode* prevPtr;
    while(currentNode->getPtr()!=NULL){
        prevPtr=currentNode;
        currentNode=currentNode->getPtr();
    }
    currentNode->setPtr(new linkedListNode);
    currentNode->getPtr()->setPtr(NULL);
    currentNode->getPtr()->setData(data);
    return head;

}

//OVERLOADED FUNCTIONS TO DELETE A NODE
linkedListNode* deleteElement(linkedListNode* head,int position){
    linkedListNode* currentNode=head;
    if(head==NULL){
        std::cout<<"LIST EMPTY\n";
        return head;
    }
    if(position<1){
        std::cout<<"POSITION DOES NOT EXIST\n";
        return head;
    }
    else if(position==1){
        head=head->getPtr();
        delete currentNode;
        return head;
    }
    else{
        linkedListNode* prevPtr=currentNode;
        currentNode=currentNode->getPtr();
        for (int i = 2; i <=position ; ++i) {
            if(currentNode==NULL){
                std::cout<<"POSITION DOES NOT EXIST\n";
                return head;
            }
            else if(i==position){
                prevPtr->setPtr(currentNode->getPtr());
                delete currentNode;
                return head;
            }
            else{
                prevPtr=currentNode;
                currentNode=currentNode->getPtr();
            }
        }
        return head;
    }
}

linkedListNode* deleteElement(linkedListNode* head){
    if(head==NULL){
        std::cout<<"LIST EMPTY\n";
        return head;
    }
    linkedListNode* currentNode=head;
    if(head->getPtr()==NULL){
        head=head->getPtr();
        delete currentNode;
        return head;
    }
    else{
        linkedListNode* prevPtr=NULL;
        while(currentNode->getPtr()!=NULL){
            prevPtr=currentNode;
            currentNode=currentNode->getPtr();
        }
        delete currentNode;
        prevPtr->setPtr(NULL);
        return head;
    }

}




int main(void){

    //LINKED LIST HEAD DECLARATION
    linkedListNode *head=NULL;


    //MENU FOR THE REQUIRED FUNCTIONALITIES
    bool program_continuity = true;
    while(program_continuity){
        std::cout<<"PLEASE SELECT AN OPTION\n";
        std::cout<<"THE MENU OPTIONS ARE\n";
        std::cout<<"1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n";
        int menuOption;
        std::cin>>menuOption;
        //SWITCH CASE FOR THE MENUS
        switch (menuOption){
            //MENU OPTION TO INSERT
            case 1:
                std::cout<<"PLEASE ENTER 1 IF YOU WANT TO INSERT AT END OR 2 AT A POSITION\n";
                int internalMenu;
                std::cin>>internalMenu;
                if(internalMenu==1){
                    std::cout<<"PLEASE ENTER THE DATA YOU WANT TO ENTER\n";
                    int data;
                    std::cin>>data;
                    head=insertElement(head,data);
                    printList(head);
                }
                else if (internalMenu==2){
                    int position;
                    std::cout<<"PLEASE ENTER THE POSITION WHERE YOU WANT TO ENTER\n";
                    std::cin>>position;
                    std::cout<<"PLEASE ENTER THE DATA YOU WANT TO ENTER\n";
                    int data;
                    std::cin>>data;
                    head=insertElement(head,data,position);
                    printList(head);
                }
                break;
                //MENU OPTION TO DELETE
            case 2:
                std::cout<<"PLEASE ENTER 1 IF YOU WANT TO DELETE AT END OR 2 AT A POSITION\n";
                std::cin>>internalMenu;
                if(internalMenu==1){
                    head=deleteElement(head);
                    printList(head);
                }
                else if (internalMenu==2){
                    int position;
                    std::cout<<"PLEASE ENTER THE DELETE WHERE YOU WANT TO ENTER\n";
                    std::cin>>position;
                    head= deleteElement(head,position);
                    printList(head);
                }
                break;
                //MENU OPTION TO DISPLAY
            case 3:
                printList(head);
                break;
            case 4:
                program_continuity= false;
                break;
                //DEFAULT OPTION TO ASK THE USER TO ENTER THE CORRECT OPTION
            default:
                std::cout<<"PLEASE ENTER THE CORRECT MENU OPTION\n";

        }
    }

}
