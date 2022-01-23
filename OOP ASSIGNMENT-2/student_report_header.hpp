#include <iostream>
//CREATING A CLASS STUDENT
class student{
    //PRIVATE ACCESS SPECIFIER TO STORE THE ATTRIBUTES
private:
    // DECLARING THE REQUIRED ATTRIBUTES OF THE CLASS
    std::string name;
    int rollNumber;
    int s1,s2,s3,s4,s5;
    //PUBLIC ACCESS SPECIFIER TO STORE THE MEMBER METHODS
public:
    // DEFAULT CONSTRUCTOR TO INITIALIZE EVERYTHING TO ZERO
    student(){
        name = "/0";
        s1=s2=s3=s4=s5=rollNumber=0;
    };
    // PARAMETERIZED CONSTRUCTOR TO TAKE NAME AND ROLL NUMBER AS PARAMETERS
    student(std::string name_,int roll_Number){
        name=name_;
        rollNumber=roll_Number;
        s1=s2=s3=s4=s5=0;
    };
    // FUNCTION TO TAKE THE DETAILS OF A STUDENT INTO THE OBJECT
    void create_report_card(){
        std::cout<<"THE CURRENT NAME IS "<<name<<"\n";
        std::cout<<"PLEASE ENTER THE NAME OF THE STUDENT IF YOU WANT TO KEEP CURRENT NAME ENTER 0\n";
        std::string potName;
        std::cin>>potName;
        if(potName!="0"){
            name=potName;
        }
        while(true){
            std::cout<<"THE CURRENT ROLL NUMBER IS "<<rollNumber<<"\n";
            std::cout<<"PLEASE ENTER THE ROLL NUMBER OF THE STUDENT IF YOU WANT TO KEEP CURRENT ROLL NUMBER ENTER 0\n";
            int potRollNumber;
            std::cin>>potRollNumber;
            if(potRollNumber!=0){
                rollNumber=potRollNumber;
            }
            if(rollNumber>=0)
                break;
            else{
                std::cout<<"PLEASE ENTER THE CORRECT ROLL NUMBER\n";
                continue;
            }
        }
        while(true){
            std::cout<<"PLEASE ENTER MARKS OF THE STUDENT IN SUBJECT 1\n";
            std::cin>>s1;
            if(s1>=0&&s1<=100)
                break;
            else{
                std::cout<<"PLEASE ENTER THE CORRECT MARKS\n";
                continue;
            }
        }
        while(true){
            std::cout<<"PLEASE ENTER MARKS OF THE STUDENT IN SUBJECT 2\n";
            std::cin>>s2;
            if(s2>=0&&s2<=100)
                break;
            else{
                std::cout<<"PLEASE ENTER THE CORRECT MARKS\n";
                continue;
            }
        }
        while(true){
            std::cout<<"PLEASE ENTER MARKS OF THE STUDENT IN SUBJECT 3\n";
            std::cin>>s3;
            if(s3>=0&&s3<=100)
                break;
            else{
                std::cout<<"PLEASE ENTER THE CORRECT MARKS\n";
                continue;
            }
        }
        while(true){
            std::cout<<"PLEASE ENTER MARKS OF THE STUDENT IN SUBJECT 4\n";
            std::cin>>s4;
            if(s4>=0&&s4<=100)
                break;
            else{
                std::cout<<"PLEASE ENTER THE CORRECT MARKS\n";
                continue;
            }
        }
        while(true){
            std::cout<<"PLEASE ENTER MARKS OF THE STUDENT IN SUBJECT 5\n";
            std::cin>>s5;
            if(s5>=0&&s5<=100)
                break;
            else{
                std::cout<<"PLEASE ENTER THE CORRECT MARKS\n";
                continue;
            }
        }

    }
    // FUNCTION TO DISPLAY A STUDENT'S DETAILS
    void display_student_details(){
      std::cout<<"NAME:"<<name<<"\n";
      std::cout<<"ROLL NUMBER:"<<rollNumber<<"\n";
      std::cout<<"THE MARKS ARE\n";
      std::cout<<"SUBJECT-1:"<<s1<<"\n";
      std::cout<<"SUBJECT-2:"<<s2<<"\n";
      std::cout<<"SUBJECT-3:"<<s3<<"\n";
      std::cout<<"SUBJECT-4:"<<s4<<"\n";
      std::cout<<"SUBJECT-5:"<<s5<<"\n";
    }
};