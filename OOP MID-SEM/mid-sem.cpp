#include <iostream>
//CLASS EMPLOYEE
class employee{
    //PRIVATE ATTRIBUTES
private:
    std::string name,designation,employeeId;
    int salary,noOfYears;
public:
    //PUBLIC MEMBER FUNCTIONS
    //DEFAULT CONSTRUCTOR
    employee(){
        this->name='\0';
        this->designation='0';
        this->employeeId='\0';
        this->salary=0;
        this->noOfYears=0;
    }
    //PARAMETERIZED CONSTRUCTOR
    employee(std::string name_,std::string employeeId_,std::string designation_,int noOfYears_){
        this->name=name_;
        this->employeeId=employeeId_;
        this->designation=designation_;
        this->noOfYears=noOfYears_;
        this->salary=0;
    }
    //DISPLAY FUNCTION
    void display(){
        std::cout<<"ID:"<<employeeId<<"  Name:"<<name<<"  Designation:"<<designation<<"\n";
    }
    //SALARY CALCULATION FUNCTION AND DISPLAY
    void calculateUpdateDisplay(){
        if(this->designation=="Manager"){
            salary=60000;
        }
        else if(this->designation=="Team Lead"){
            salary=450000;
        }
        else if(this->designation=="Programmer"){
            salary=30000;
        }

        if(this->noOfYears>=5){
            salary+=5000;
        }
        this->display();
        std::cout<<"Salary:"<<this->salary<<"\n";
    }


};


//MAIN FUNCTION

int main(void){
    //SIZE OF ARRAY
    int maxEmployees;
    std::cout<<"PLEASE ENTER THE MAXIMUM NUMBER OF EMPLOYEES\n";
    std::cin>>maxEmployees;
    //ARRAY OF OBJECTS
    employee* reqArray= new employee[maxEmployees];
    int lastArrayMember=0;
    //MENU
    while(true){
        std::cout<<"THE MENU OPTIONS ARE\n";
        std::cout<<"1. Create Record\n"
                   "2. Display\n"
                   "3. Calculate, Update and Display\n"
                   "4. Exit.\n";
        std::cout<<"PLEASE ENTER THE REQUIRED OPTION\n";
        int menuOption;
        std::cin>>menuOption;
        //CREATE RECORD MENU OPTION
        if(menuOption==1){
            std::string name,employeeId,designation;
            int noOfYears;
            //TAKING IN ALL DETAILS
            std::cout<<"PLEASE ENTER THE NAME OF THE EMPLOYEE\n";
            std::cin.ignore();
            std::getline(std::cin,name);
            std::cout<<"PLEASE ENTER THE EMPLOYEE ID\n";
            std::cin>>employeeId;
            std::cout<<"PLEASE ENTER THE DESIGNATION EXACTLY ";
            std::cout<<"Manager or Team Lead or Programmer\n";
            std::cin.ignore();
            std::getline(std::cin,designation);
            std::cout<<"PLEASE ENTER THE NUMBER OF YEARS WITH THE ORGANIZATION\n";
            std::cin>>noOfYears;
            if(noOfYears<1){
                std::cout<<"NUMBER OF YEARS CANNOT BE LESS THAN 1\n";
                continue;
            }
            //PARAMETERIZED CONSTRUCTOR TO PUT DETAILS IN THE ARRAY OF OBJECTS
            reqArray[lastArrayMember]=employee(name,employeeId,designation,noOfYears);
            lastArrayMember+=1;
        }
        else if(menuOption==2){
            //DISPLAYING ALL MEMBERS
            std::cout<<"THE EMPLOYEES DETAILS ARE\n";
            for (int i = 0; i < lastArrayMember ; ++i) {
                reqArray[i].display();
            }

        }
        else if(menuOption==3){
            //DISPLAYING MEMBERS BY UPDATING SALARY
            for (int i = 0; i < lastArrayMember ; ++i) {
                reqArray[i].calculateUpdateDisplay();
            }

        }
        else if(menuOption==4){
            //EXIT
            std::cout<<"GOODBYE!\n";
            break;
        }
        else{
            std::cout<<"PLEASE ENTER THE CORRECT OPTION\n";
        }
    }
}