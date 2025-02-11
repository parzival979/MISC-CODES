#include <iostream>
//INCLUDING THE HEADER FILE
#include "student_report_header.hpp"
int main(void){
    //CREATING OBJECTS FOR THE FIRST 3 STUDENTS
    student stu1,stu2,stu3;
    //TAKING INPUT OF NAMES AND ROLL NUMBERS OF STUDENTS 4 AND 5
    std::string stu4Name,stu5Name;
    int stu4RollNumber,stu5RollNumber;
    std::cout<<"PLEASE ENTER THE NAME OF STUDENT 4\n";
    std::cin>>stu4Name;
    while(true){
        std::cout<<"PLEASE ENTER THE ROLL NUMBER OF STUDENT 4\n";
        std::cin>>stu4RollNumber;
        if(stu4RollNumber>=0)
            break;
        else{
            std::cout<<"PLEASE ENTER THE CORRECT ROLL NUMBER\n";
            continue;
        }
    }
    std::cout<<"PLEASE ENTER THE NAME OF STUDENT 5\n";
    std::cin>>stu5Name;
    while(true){
        std::cout<<"PLEASE ENTER THE ROLL NUMBER OF STUDENT 5\n";
        std::cin>>stu5RollNumber;
        if(stu5RollNumber>=0)
            break;
        else{
            std::cout<<"PLEASE ENTER THE CORRECT ROLL NUMBER\n";
            continue;
        }
    }
    //USING PARAMETERIZED CONSTRUCTOR TO FILL IN THE STUDENT DETAILS
    student stu4(stu4Name,stu4RollNumber);
    student stu5(stu5Name,stu5RollNumber);
    //MENU TO ENTER STUDENT DETAILS OR VIEW STUDENT DETAILS
    while(true){
        int menuOption;
        std::cout<<"PLEASE ENTER 1 TO ENTER A STUDENT'S DETAILS,2 TO DISPLAY ALL STUDENTS DETAILS ELSE 0\n";
        std::cin>>menuOption;
        // MENU OPTION TO TAKE STUDENT DETAILS
        if(menuOption==1){
            int subMenuOption;
            std::cout<<"PLEASE ENTER THE NUMBER OF THE STUDENT YOU WANT TO ENTER DETAILS FOR\n";
            std::cin>>subMenuOption;
            //SWITCH CASE TO ENTER SELECTED STUDENTS DETAILS
            switch (subMenuOption) {
                case 1:
                    stu1.create_report_card();
                    break;
                case 2:
                    stu2.create_report_card();
                    break;
                case 3:
                    stu3.create_report_card();
                    break;
                case 4:
                    stu4.create_report_card();
                    break;
                case 5:
                    stu5.create_report_card();
                    break;
                default:
                    std::cout<<"PLEASE ENTER THE CORRECT STUDENT NUMBER\n";
                    break;
            }
        }
        // MENU OPTION TO DISPLAY THE STUDENT DETAILS
        else if(menuOption==2){
            std::cout<<"THE STUDENT 1 DETAILS ARE\n";
            stu1.display_student_details();
            std::cout<<"THE STUDENT 2 DETAILS ARE\n";
            stu2.display_student_details();
            std::cout<<"THE STUDENT 3 DETAILS ARE\n";
            stu3.display_student_details();
            std::cout<<"THE STUDENT 4 DETAILS ARE\n";
            stu4.display_student_details();
            std::cout<<"THE STUDENT 5 DETAILS ARE\n";
            stu5.display_student_details();
        }
        else{
            break;
        }
    }
}