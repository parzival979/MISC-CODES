#include <iostream>


template <class t>class person{
protected:
    std::string name;
    t rollNumber;
public:
    person(){

    }
    person(std::string nam,t num){
        name=nam;
        rollNumber=num;
    }
    void displayMember(){
        std::cout<<"THE NAME IS:"<<name<<"\n";
        std::cout<<"THE ROLL-NUMBER IS:"<<rollNumber<<"\n";
    }

};

class student:virtual protected person<std::string>{
protected:
    std::string course1,course2,course3;
public:
    student(){
        course1="\0";
        course2="\0";
        course3="\0";
    }
    student(std::string c1,std::string c2,std::string c3,std::string nam,std::string number): person(nam,number){
        course1=c1;
        course2=c2;
        course3=c3;
    };
    void displayMember(){
        std::cout<<"THE NAME IS:"<<name<<"\n";
        std::cout<<"THE ROLL-NUMBER IS:"<<rollNumber<<"\n";
        std::cout<<"THE COURSE ARE:"<<course1<<","<<course2<<","<<course3<<"\n";
    }
};

class researchStudent:virtual protected person<int>{
protected:
    std::string course1,researchArea;
public:
    researchStudent(){
        course1="\0";
        researchArea="\0";
    }
    researchStudent(std::string c1,std::string research,int number,std::string nam): person(nam,number){
        course1=c1;
        researchArea=research;
    }
    void displayMember(){
        std::cout<<"THE NAME IS:"<<name<<"\n";
        std::cout<<"THE ROLL-NUMBER IS:"<<rollNumber<<"\n";
        std::cout<<"THE COURSE IS:"<<course1<<"\n";
        std::cout<<"THE RESEARCH AREA IS:"<<researchArea<<"\n";
    }

};

class tA:protected student,protected researchStudent{
protected:
    std::string courseAssigned,role;
public:
    tA(){
        courseAssigned="\0";
        role="\0";
    }
    tA(std::string courseAss,std::string role_,std::string c1,std::string c2,std::string c3,std::string nam,std::string number):student(c1,c2,c3,nam,number),person<std::string>(nam,number),person<int>(nam,0){
        courseAssigned=courseAss;
        role=role_;
    }
    tA(std::string courseAss,std::string role_,std::string c1,std::string research,int number,std::string nam): researchStudent(c1,research,number,nam),person<int>(nam,number),
                                                                                                                person<std::string>(nam,"\0"){
        courseAssigned=courseAss;
        role=role_;
    }
    void displayMember(){
        char menuOption;
        std::cout<<"PLEASE SELECT THE MENU OPTION\n";
        std::cout<<"a) Person\n"
                   "b) Student\n"
                   "c) Research Student\n"
                   "d) Teaching Assistant\n";
        std::cin>>menuOption;
        if(menuOption=='a'){
            if(role=="student")
            person<std::string>::displayMember();
            else if(role=="research student")
            person<int>::displayMember();
        }
        else if(menuOption=='b'){
            if(role=="student")
                student::displayMember();
            else
                std::cout<<"NOT A STUDENT\n";
        }
        else if(menuOption=='c'){
            if(role=="research student")
                researchStudent::displayMember();
            else
                std::cout<<"NOT A RESEARCH STUDENT\n";
        }
        else if(menuOption=='d'){
            if(role=="student"){
                person<std::string>::displayMember();
                std::cout<<"THE COURSE ASSIGNED IS:"<<courseAssigned<<"\n";
                std::cout<<"THE ROLE IS:"<<role<<"\n";

            }
            else if(role=="research student"){
                person<int>::displayMember();
                std::cout<<"THE COURSE ASSIGNED IS:"<<courseAssigned<<"\n";
                std::cout<<"THE ROLE IS:"<<role<<"\n";

            }


        }
        else{
            std::cout<<"PLEASE ENTER THE CORRECT OPTION\n";
        }
    }
    std::string getName(){
        if(role=="student")
            return person<std::string>::name;
        else if(role=="research student")
            return person<int>::name;
        else
            return "\0";
    }

};

class linkedListNode{
public:
    tA* objectPtr;
    linkedListNode* nextNodePtr;
};
int main(void){
    linkedListNode* head=NULL;
    while(true){
        int menuOption;
        std::cout<<"PLEASE CHOOSE THE APPROPRIATE MENU OPTION\n";
        std::cout<<"1. Set TA Details\n"
                   "2. Display\n"
                   "3. Exit\n";
        std::cin>>menuOption;
        if(menuOption==1){
            int internalMenu;
            std::cout<<"PLEASE ENTER 1 FOR STUDENT,2 FOR RESEARCH STUDENT\n";
            std::cin>>internalMenu;
            std::string name,rollNumberStr,course1,course2,course3,researchArea,courseAssigned,role;
            int rollNumberInt;
            tA *temp;
            linkedListNode *headTemp;
            if(internalMenu==1){
                role="student";
                std::cout<<"PLEASE ENTER THE NAME OF THE STUDENT\n";
                std::cin.ignore();
                std::getline(std::cin,name);
                std::cout<<"PLEASE ENTER THE ROLL NUMBER OF THE STUDENT\n";
                std::cin>>rollNumberStr;
                std::cout<<"PLEASE ENTER COURSE 1 OF THE STUDENT\n";
                std::cin.ignore();
                std::getline(std::cin,course1);
                std::cout<<"PLEASE ENTER COURSE 2 OF THE STUDENT\n";
                std::getline(std::cin,course2);
                std::cout<<"PLEASE ENTER COURSE 3 OF THE STUDENT\n";
                std::getline(std::cin,course3);
                std::cout<<"PLEASE ENTER THE COURSE ASSIGNED AS TA\n";
                std::getline(std::cin,courseAssigned);
                if(courseAssigned==course1||courseAssigned==course2||courseAssigned==course3){
                    std::cout<<"COURSE ASSIGNED SHOULD NOT MATCH WITH COURSES CURRENTLY TAKING\n";
                    continue;
                }
                temp=new tA(courseAssigned,role,course1,course2,course3,name,rollNumberStr);
            }
            else if(internalMenu==2){
                role="research student";
                std::cout<<"PLEASE ENTER THE NAME OF THE RESEARCH STUDENT\n";
                std::cin.ignore();
                std::getline(std::cin,name);
                std::cout<<"PLEASE ENTER THE ROLL NUMBER OF THE RESEARCH STUDENT\n";
                std::cin>>rollNumberInt;
                std::cout<<"PLEASE ENTER COURSE 1 OF THE RESEARCH STUDENT\n";
                std::cin.ignore();
                std::getline(std::cin,course1);
                std::cout<<"PLEASE ENTER THE RESEARCH AREA OF THE RESEARCH STUDENT\n";
                std::getline(std::cin,researchArea);
                std::cout<<"PLEASE ENTER THE COURSE ASSIGNED AS TA\n";
                std::getline(std::cin,courseAssigned);
                if(courseAssigned==course1){
                    std::cout<<"COURSE ASSIGNED SHOULD NOT MATCH WITH COURSES CURRENTLY TAKING\n";
                    continue;
                }
                temp=new tA(courseAssigned,role,course1,researchArea,rollNumberInt,name);

            }
            else{
                std::cout<<"PLEASE ENTER A VALID OPTION\n";
                continue;
            }
            headTemp=head;
            head=new linkedListNode;
            head->objectPtr=temp;
            head->nextNodePtr=headTemp;
        }
        else if(menuOption==2){
            std::string name;
            std::cout<<"PLEASE ENTER THE FULL NAME OF THE TA TO DISPLAY DETAILS\n";
            std::cin.ignore();
            std::getline(std::cin,name);
            linkedListNode* currentNodePtr=head;
            tA* temp=NULL;
            while(currentNodePtr!=NULL){
                if(currentNodePtr->objectPtr->getName()==name){
                    temp=currentNodePtr->objectPtr;
                    break;
                }
                currentNodePtr=currentNodePtr->nextNodePtr;
            }
            if(temp!=NULL){
                temp->displayMember();
            }
            else
                std::cout<<"STUDENT DOES NOT EXIST\n";
        }
        else if(menuOption==3){
            std::cout<<"GOODBYE\n";
            break;
        }
        else{
            std::cout<<"PLEASE ENTER THE CORRECT OPTION\n";
        }
    }

}