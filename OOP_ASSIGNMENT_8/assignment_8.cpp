#include <iostream>
//EMPLOYEE CLASS
class employee{
protected:
    int employeeId;
    std::string employeeName;
};

//CONTRACT INHERITED CLASS
class contract : protected employee{
protected:
    double payPerHour;
public:
    void setPay(double pay){
        payPerHour=pay;
    }
    double getPay(){
        return payPerHour;
    };
};

//SALARIED INHERITED CLASS
class salaried : protected employee{
protected:
    double monthlyPay;
public:
    void setPay(double pay){
        monthlyPay=pay;
    }
    double getPay(){
        return monthlyPay;
    };

};

//MANAGER INHERITED CLASS
class manager : private salaried{
public:
    void setDetails(int id,std::string name,double pay){
        employeeId=id;
        employeeName=name;
        monthlyPay=pay;
    }
    void getDetails(){
        std::cout<<"ID:"<<employeeId<<"  NAME:"<<employeeName<<"  SALARY:"<<monthlyPay<<"\n";
    }
    int getId(){
        return employeeId;
    }
    void setSalary(double salary){
        monthlyPay=salary;
    };
    double calculateSalary(int months){
        return months*monthlyPay;
    }
};

//INTERN INHERITED CLASS
class intern : private contract{
public:
    void setDetails(int id,std::string name,double pay){
        employeeId=id;
        employeeName=name;
        payPerHour=pay;
    }
    void getDetails(){
        std::cout<<"ID:"<<employeeId<<"  NAME:"<<employeeName<<"  SALARY:"<<payPerHour<<"\n";
    }
    int getId(){
        return employeeId;
    }
    void setSalary(double pay){
        payPerHour=pay;
    }
    double calculateSalary(int hours){
        return hours*payPerHour;
    }
};

int main(void){
    int maxManagers,maxInterns;
    std::cout<<"PLEASE ENTER THE MAXIMUM NUMBER OF MANAGERS\n";
    std::cin>>maxManagers;
    std::cout<<"PLEASE ENTER THE MAXIMUM NUMBER OF INTERNS\n";
    std::cin>>maxInterns;
    //REQUIRED ARRAYS TO STORE DATA
    manager managerArray[maxManagers];
    intern internArray[maxInterns];
    int lastManagerNumber=0,lastInternNumber=0;
    while(true){
        int menuOption;
        std::cout<<"PLEASE CHOSE A MENU OPTION AND ENTER THE NUMBER\n";
        std::cout<<"THE MENU OPTIONS ARE\n"
                 << "1.Create Employee (Manager or Intern)\n"
                 << "2.Update Employee Details (Manager or Intern)\n"
                 <<  "3.Print Employee Details (Manager or Intern)\n"
                 <<  "4.Update Pay (Manager or Intern)\n"
                 <<  "5.Calculate Salary (Manager or Intern)\n"
                 <<  "6.Exit\n";
        std::cin>>menuOption;
        if(menuOption==1){
            int internalMenuOption;
            std::cout<<"PLEASE ENTER 1 FOR MANAGER 2 FOR INTERN\n";
            std::cin>>internalMenuOption;
            if(internalMenuOption==1){
                int id;
                double pay;
                std::string name;
                std::cout<<"PLEASE ENTER THE NAME OF THE MANAGER\n";
                std::cin>>name;
                std::cout<<"PLEASE ENTER THE EMPLOYEE ID\n";
                std::cin>>id;
                std::cout<<"PLEASE ENTER THE EMPLOYEE SALARY\n";
                std::cin>>pay;
                if(id<=0||pay<=0){
                    std::cout<<"ID OR PAY CANNOT BE LESS THAN OR EQUAL TO ZERO\n";
                    continue;
                }
                managerArray[lastManagerNumber].setDetails(id,name,pay);
                lastManagerNumber+=1;
            }
            else if(internalMenuOption==2){
                int id;
                double pay;
                std::string name;
                std::cout<<"PLEASE ENTER THE NAME OF THE INTERN\n";
                std::cin>>name;
                std::cout<<"PLEASE ENTER THE EMPLOYEE ID\n";
                std::cin>>id;
                std::cout<<"PLEASE ENTER THE EMPLOYEE SALARY PER HOUR\n";
                std::cin>>pay;
                if(id<=0||pay<=0){
                    std::cout<<"ID OR PAY CANNOT BE LESS THAN OR EQUAL TO ZERO\n";
                    continue;
                }
                internArray[lastInternNumber].setDetails(id,name,pay);
                lastInternNumber+=1;
            }
            else{
                std::cout<<"PLEASE ENTER THE CORRECT OPTION\n";
            }
        }
        else if(menuOption==2){
            int internalMenuOption;
            std::cout<<"PLEASE ENTER 1 FOR MANAGER 2 FOR INTERN\n";
            std::cin>>internalMenuOption;
            int reqLocation=-1;
            if(internalMenuOption==1){
                int id;
                std::cout<<"PLEASE ENTER THE MANAGER ID\n";
                std::cin>>id;
                for (int i = 0; i < lastManagerNumber; ++i) {
                    if(managerArray[i].getId()==id){
                        reqLocation=i;
                        break;
                    }
                }
                if(reqLocation!=-1){
                    double pay;
                    std::string name;
                    std::cout<<"PLEASE ENTER THE NAME OF THE MANAGER\n";
                    std::cin>>name;
                    std::cout<<"PLEASE ENTER THE EMPLOYEE ID\n";
                    std::cin>>id;
                    std::cout<<"PLEASE ENTER THE EMPLOYEE SALARY\n";
                    std::cin>>pay;
                    if(id<=0||pay<=0){
                        std::cout<<"ID OR PAY CANNOT BE LESS THAN OR EQUAL TO ZERO\n";
                        continue;
                    }
                    managerArray[reqLocation].setDetails(id,name,pay);
                }
                else{
                    std::cout<<"EMPLOYEE ID NOT FOUND\n";
                }

            }
            else if(internalMenuOption==2){
                int id;
                std::cout<<"PLEASE ENTER THE INTERN ID\n";
                std::cin>>id;
                for (int i = 0; i < lastInternNumber; ++i) {
                    if(internArray[i].getId()==id){
                        reqLocation=i;
                        break;
                    }
                }
                if(reqLocation!=-1){
                    double pay;
                    std::string name;
                    std::cout<<"PLEASE ENTER THE NAME OF THE INTERN\n";
                    std::cin>>name;
                    std::cout<<"PLEASE ENTER THE EMPLOYEE ID\n";
                    std::cin>>id;
                    std::cout<<"PLEASE ENTER THE EMPLOYEE SALARY\n";
                    std::cin>>pay;
                    if(id<=0||pay<=0){
                        std::cout<<"ID OR PAY CANNOT BE LESS THAN OR EQUAL TO ZERO\n";
                        continue;
                    }
                    internArray[reqLocation].setDetails(id,name,pay);
                }
                else{
                    std::cout<<"EMPLOYEE ID NOT FOUND\n";
                }

            }
            else{
                std::cout<<"PLEASE ENTER THE CORRECT OPTION\n";
            }

        }
        else if(menuOption==3){
            int internalMenuOption;
            std::cout<<"PLEASE ENTER 1 FOR MANAGER 2 FOR INTERN\n";
            std::cin>>internalMenuOption;
            int reqLocation=-1;
            if(internalMenuOption==1){
                int id;
                std::cout<<"PLEASE ENTER THE MANAGER ID\n";
                std::cin>>id;
                for (int i = 0; i < lastManagerNumber; ++i) {
                    if(managerArray[i].getId()==id){
                        reqLocation=i;
                        break;
                    }
                }

                if(reqLocation!=-1){
                    managerArray[reqLocation].getDetails();
                }
                else{
                    std::cout<<"EMPLOYEE ID NOT FOUND\n";
                }

            }
            else if(internalMenuOption==2){
                int id;
                std::cout<<"PLEASE ENTER THE INTERN ID\n";
                std::cin>>id;
                for (int i = 0; i < lastInternNumber; ++i) {
                    if(internArray[i].getId()==id){
                        reqLocation=i;
                        break;
                    }
                }

                if(reqLocation!=-1){
                    internArray[reqLocation].getDetails();
                }
                else{
                    std::cout<<"EMPLOYEE ID NOT FOUND\n";
                }
            }
            else{
                std::cout<<"PLEASE ENTER THE CORRECT OPTION\n";
            }

        }
        else if(menuOption==4){
            int internalMenuOption;
            std::cout<<"PLEASE ENTER 1 FOR MANAGER 2 FOR INTERN\n";
            std::cin>>internalMenuOption;
            int reqLocation=-1;
            if(internalMenuOption==1){
                int id;
                std::cout<<"PLEASE ENTER THE MANAGER ID\n";
                std::cin>>id;
                for (int i = 0; i < lastManagerNumber; ++i) {
                    if(managerArray[i].getId()==id){
                        reqLocation=i;
                        break;
                    }
                }

                if(reqLocation!=-1){
                    double pay;
                    std::cout<<"PLEASE ENTER THE EMPLOYEE SALARY\n";
                    std::cin>>pay;
                    if(pay<=0){
                        std::cout<<"PAY CANNOT BE LESS THAN OR EQUAL TO ZERO\n";
                        continue;
                    }
                    managerArray[reqLocation].setSalary(pay);
                }
                else{
                    std::cout<<"EMPLOYEE ID NOT FOUND\n";
                }

            }
            else if(internalMenuOption==2){
                int id;
                std::cout<<"PLEASE ENTER THE INTERN ID\n";
                std::cin>>id;
                for (int i = 0; i < lastInternNumber; ++i) {
                    if(internArray[i].getId()==id){
                        reqLocation=i;
                        break;
                    }
                }

                if(reqLocation!=-1){
                    double pay;
                    std::cout<<"PLEASE ENTER THE EMPLOYEE SALARY\n";
                    std::cin>>pay;
                    if(pay<=0){
                        std::cout<<"PAY CANNOT BE LESS THAN OR EQUAL TO ZERO\n";
                        continue;
                    }
                    internArray[reqLocation].setSalary(pay);
                }
                else{
                    std::cout<<"EMPLOYEE ID NOT FOUND\n";
                }

            }
            else{
                std::cout<<"PLEASE ENTER THE CORRECT OPTION\n";
            }

        }
        else if(menuOption==5){
            int internalMenuOption;
            std::cout<<"PLEASE ENTER 1 FOR MANAGER 2 FOR INTERN\n";
            std::cin>>internalMenuOption;
            int reqLocation=-1;
            if(internalMenuOption==1){
                int id;
                std::cout<<"PLEASE ENTER THE MANAGER ID\n";
                std::cin>>id;
                for (int i = 0; i < lastManagerNumber; ++i) {
                    if(managerArray[i].getId()==id){
                        reqLocation=i;
                        break;
                    }
                }

                if(reqLocation!=-1){
                    std::cout<<"PLEASE ENTER THE NUMBER OF MONTHS FOR THE SALARY\n";
                    int months;
                    std::cin>>months;
                    if(months<=0){
                        std::cout<<"NUMBER OF MONTHS CANNOT BE LESS THAN OR EQUAL TO ZERO\n";
                        continue;
                    }
                    std::cout<<"THE SALARY OF THE MANAGER FOR "<<months<<" MONTHS IS"<<managerArray[reqLocation].calculateSalary(months);
                }
                else{
                    std::cout<<"EMPLOYEE ID NOT FOUND\n";
                }

            }
            else if(internalMenuOption==2){
                int id;
                std::cout<<"PLEASE ENTER THE INTERN ID\n";
                std::cin>>id;
                for (int i = 0; i < lastInternNumber; ++i) {
                    if(internArray[i].getId()==id){
                        reqLocation=i;
                        break;
                    }
                }

                if(reqLocation!=-1){
                    std::cout<<"PLEASE ENTER THE NUMBER OF HOURS FOR THE SALARY\n";
                    int hours;
                    std::cin>>hours;
                    if(hours<=0){
                        std::cout<<"NUMBER OF MONTHS CANNOT BE LESS THAN OR EQUAL TO ZERO\n";
                        continue;
                    }
                    std::cout<<"THE SALARY OF THE INTERN FOR "<<hours<<"HOURS IS"<<internArray[reqLocation].calculateSalary(hours);

                }
                else{
                    std::cout<<"EMPLOYEE ID NOT FOUND\n";
                }

            }
            else{
                std::cout<<"PLEASE ENTER THE CORRECT OPTION\n";
            }

        }
        else if(menuOption==6){
            std::cout<<"GOODBYE\n";
            break;
        }
        else{
            std::cout<<"PLEASE SELECT THE CORRECT MENU OPTION\n";
        }
    }


}
