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


    //METHOD TO ADD LINKED LIST NODE WITH DATA IN SORTED ORDER
    //AUTOMATICALLY ENTERS THE NODE IN SORTED ORDER
    linkedListNode* addListNode(int data1,linkedListNode *head){
        linkedListNode* currentNode=head;
        if(currentNode->getPtr()==NULL && data1>=currentNode->getData()){
            currentNode->setPtr(new linkedListNode);
            currentNode->getPtr()->setData(data1);
            currentNode->getPtr()->setPtr(NULL);
            return head;
        }
        else if(currentNode->getPtr()==NULL && data1<currentNode->getData()){
            head = new linkedListNode;
            head->setData(data1);
            head->setPtr(currentNode);
            return head;
        }
        else{
            while(true){
                if(currentNode==head && data1<=currentNode->getData()){
                    head = new linkedListNode;
                    head->setData(data1);
                    head->setPtr(currentNode);
                    return head;
                }
                else if(currentNode->getPtr()==NULL && data1>=currentNode->getData()){
                    currentNode->setPtr(new linkedListNode);
                    currentNode->getPtr()->setData(data1);
                    currentNode->getPtr()->setPtr(NULL);
                    return head;
                }
                else if(currentNode->getPtr()==NULL && data1<currentNode->getData()){
                    head = new linkedListNode;
                    head->setData(data1);
                    head->setPtr(currentNode);
                    return head;
                }
                else if(data1>=currentNode->getData() && data1<=currentNode->getPtr()->getData()){
                    linkedListNode* nextPtr=currentNode->getPtr();
                    currentNode->setPtr(new linkedListNode);
                    currentNode->getPtr()->setData(data1);
                    currentNode->getPtr()->setPtr(nextPtr);
                    return head;
                }
                currentNode=currentNode->getPtr();
            }
        }
    }


    //METHOD TO PRINT THE LINKED LIST
    void printList(linkedListNode *head){
        std::cout<<"THE LIST IS\n";
        linkedListNode* currentNode=head;
        while(currentNode!=NULL){
            std::cout<<currentNode->getData();
            currentNode=currentNode->getPtr();
            if(currentNode!=NULL)
                std::cout<<"->";
        }
        std::cout<<"\n";
    }


    //METHOD TO DELETE A GIVEN NODE AT A GIVEN POSITION
    linkedListNode* deleteAtPosition(linkedListNode* head,int position){
        linkedListNode* currentNode=head;
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


    //METHOD TO MERGE LISTS
    linkedListNode* mergeLists(linkedListNode* head1,linkedListNode* head2){
        int data1;
        while(head2 != NULL){
            data1=head2->getData();
            linkedListNode *currentPtr;
            currentPtr=head2;
            head2=head2->getPtr();
            delete currentPtr;
            head1=head1->addListNode(data1,head1);
        }
        return head1;
    }

};



int main(void){

    //LINKED LIST HEAD DECLARATION
    linkedListNode *head1=NULL,*head2=NULL;


    //MENU FOR THE REQUIRED FUNCTIONALITIES
    bool program_continuity = true;
    while(program_continuity){
        std::cout<<"PLEASE SELECT AN OPTION\n";
        std::cout<<"THE MENU OPTIONS ARE\n";
        std::cout<<"1.INSERT\n2.DELETE\n3.DISPLAY\n4.MERGE\n5.EXIT\n";
        int menuOption;
        std::cin>>menuOption;
        //SWITCH CASE FOR THE MENUS
        switch (menuOption){

            //OPTION TO ENTER A NODE INTO THE LINKED LIST IN SORTED ORDER
            //AUTOMATICALLY ENTERS THE NODE IN SORTED ORDER
            case 1:
                std::cout<<"PLEASE ENTER THE LIST INTO WHICH YOU WANT TO ENTER,1 OR 2\n";
                int listNumber;
                std::cin>>listNumber;
                if(listNumber==1){
                    std::cout<<"PLEASE ENTER THE NUMBER YOU WANT TO ENTER\n";
                    std::cin>>listNumber;
                    if(head1==NULL){
                        head1= new linkedListNode;
                        head1->setData(listNumber);
                        head1->setPtr(NULL);
                    }
                    else
                        head1=head1->addListNode(listNumber,head1);
                    head1->printList(head1);
                }
                else if(listNumber==2){
                    std::cout<<"PLEASE ENTER THE NUMBER YOU WANT TO ENTER\n";
                    std::cin>>listNumber;
                    if(head2==NULL){
                        head2= new linkedListNode;
                        head2->setData(listNumber);
                        head2->setPtr(NULL);
                    }
                    else
                        head2=head2->addListNode(listNumber,head2);
                    head2->printList(head2);

                }
                else{
                    std::cout<<"PLEASE ENTER THE CORRECT NUMBER\n";
                }
                break;

            //OPTION TO DELETE A NODE FROM THE LINKED LISTS
            case 2:
                std::cout<<"PLEASE ENTER THE LIST FROM WHICH YOU WANT TO DELETE,1 OR 2\n";
                std::cin>>listNumber;
                if(listNumber==1){
                    if(head1==NULL){
                        std::cout<<"LIST EMPTY\n";
                    }
                    else{
                        std::cout<<"PLEASE ENTER A POSITION BEGINNING FROM 1\n";
                        std::cout<<"PLEASE ENTER THE POSITION ON THE LIST YOU WANT TO DELETE FROM\n";
                        std::cin>>listNumber;
                        head1=head1->deleteAtPosition(head1,listNumber);
                        head1->printList(head1);
                    }

                }
                else if(listNumber==2){
                    if(head2==NULL){
                        std::cout<<"LIST EMPTY\n";
                    }
                    else{
                        std::cout<<"PLEASE ENTER A POSITION BEGINNING FROM 1\n";
                        std::cout<<"PLEASE ENTER THE POSITION ON THE LIST YOU WANT TO DELETE FROM\n";
                        std::cin>>listNumber;
                        head2=head2->deleteAtPosition(head2,listNumber);
                        head2->printList(head2);
                    }
                }
                else{
                    std::cout<<"PLEASE ENTER THE CORRECT NUMBER\n";
                }
                break;

            //OPTION TO PRINT THE LINKED LISTS
            case 3:
                std::cout<<"PLEASE ENTER THE LIST FROM WHICH YOU WANT TO DISPLAY,1 OR 2\n";
                std::cin>>listNumber;
                if(listNumber==1){
                    if(head1==NULL){
                        std::cout<<"LIST EMPTY\n";
                    }
                    else{
                        head1->printList(head1);
                    }
                }
                else if(listNumber==2){
                    if(head2==NULL){
                        std::cout<<"LIST EMPTY\n";
                    }
                    else{
                        head2->printList(head2);
                    }
                }
                else{
                    std::cout<<"PLEASE ENTER THE CORRECT NUMBER\n";
                }
                break;

            //OPTION TO MERGE THE LINKED LISTS
            case 4:
                if(head1==NULL){
                    std::cout<<"LIST 1 EMPTY\n";
                }
                else if(head2==NULL){
                    std::cout<<"LIST 2 EMPTY\n";
                }
                else{
                    head1=head1->mergeLists(head1,head2);
                    std::cout<<"THE MERGED LIST 1 IS\n";
                    head1->printList(head1);
                    head2=NULL;
                }
                break;

            //OPTION TO EXIT THE PROGRAM
            case 5:
                program_continuity= false;
                break;

            //DEFAULT OPTION TO ASK THE USER TO ENTER THE CORRECT OPTION
            default:
                std::cout<<"PLEASE ENTER THE CORRECT MENU OPTION\n";

        }
    }

}
