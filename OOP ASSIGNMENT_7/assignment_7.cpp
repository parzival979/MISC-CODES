#include <iostream>
// CLASS FOR ACCOUNT
class account{
    //PROTECTED ATTRIBUTES
protected:
    double accountBalance;
    int accountNumber;
    //PUBLIC METHODS
public:
    account(){
        accountBalance=0;
        accountNumber=0;
    }
    account(double balance,int acNumber){
        accountNumber=acNumber;
        if(balance<=0){
            accountBalance=0;
            std::cout<<"PLEASE ENTER ACCOUNT BALANCE GREATER THAN 0\n";
            std::cout<<"THE CURRENT ACCOUNT BALANCE IS SET TO ZERO\n";
        }
        else{
            accountBalance=balance;
        }
    }
    void credit(double creditAmount){
            accountBalance+=creditAmount;
    }
    bool debit(double debitAmount){
        if(accountBalance-debitAmount<0){
            std::cout<<"DEBIT AMOUNT EXCEEDS ACCOUNT BALANCE,TRANSACTION FAILED\n";
            return false;
        }
        else
            accountBalance-=debitAmount;
        return true;
    }
    double getBalance(){
        return accountBalance;
    }
    int getAcNumber(){
        return accountNumber;
    }
};
//INHERITED SAVINGS CLASS
class savingsAccount : public account{
protected:
    double interestRate;
public:
    savingsAccount():account(){
        interestRate=0;
    }
    savingsAccount(double balance,int acNumber,double interest) : account(balance,acNumber){
        accountNumber=acNumber;
        interestRate=interest;
        if(balance<=0){
            accountBalance=0;
            std::cout<<"PLEASE ENTER ACCOUNT BALANCE GREATER THAN 0\n";
            std::cout<<"THE CURRENT ACCOUNT BALANCE IS SET TO ZERO\n";
        }
        else{
            accountBalance=balance;
        }

    }
    double calculateInterest(){
        return interestRate*accountBalance;
    }

    void setInterest(double interest){
        interestRate=interest;
    }

    double getInterest(){
        return interestRate;
    }
};

//INHERITED CHECKING CLASS
class checkingAccount : public account{
protected:
    double feeAmount;
public:
    checkingAccount():account(){
        feeAmount=0;
    }
    checkingAccount(double balance,int acNumber,double checkingFee):account(balance,acNumber){
        accountNumber=acNumber;
        feeAmount=checkingFee;
        if(balance<=0){
            accountBalance=0;
            std::cout<<"PLEASE ENTER ACCOUNT BALANCE GREATER THAN 0\n";
            std::cout<<"THE CURRENT ACCOUNT BALANCE IS SET TO ZERO\n";
        }
        else{
            accountBalance=balance;
        }
    }
    void credit(double creditAmount){
        account::credit(creditAmount);
        account::debit(feeAmount);
    }
    bool debit(double debitAmount){
        if(account::debit(debitAmount)){
            debitFee();
            return true;
        }
        else
            return false;
    }

    void setFee(double fee){
        feeAmount=fee;
    }

    void debitFee(){
        account::debit(feeAmount);
    }

    double getFee(){
        return feeAmount;
    }
};

//SAVINGS ACCOUNT LINKED LIST
class savingsLL{
public:
    savingsAccount* listAccountPtr;
    savingsLL* nextNodePtr;
};

savingsAccount* findAccount(int acNumber,savingsLL* savingsHead){
    savingsAccount* currentAcPtr=savingsHead->listAccountPtr;
    savingsLL* savingsPtr=savingsHead->nextNodePtr;
    while(true){
        if (currentAcPtr->getAcNumber() == acNumber) {
            return currentAcPtr;
        }
        else if (savingsPtr==NULL){
            return NULL;
        }
        else{
            currentAcPtr=savingsPtr->listAccountPtr;
            savingsPtr=savingsPtr->nextNodePtr;
        }
    }
}
//CHECKING ACCOUNT LINKED LIST
class checkingLL{
public:
    checkingAccount* listAccountPtr;
    checkingLL* nextNodePtr;
};


checkingAccount* findAccount(int acNumber,checkingLL* checkingHead){
    checkingAccount* currentAcPtr=checkingHead->listAccountPtr;
    checkingLL* checkingPtr=checkingHead->nextNodePtr;
    while(true){
        if (currentAcPtr->getAcNumber() == acNumber){
            return currentAcPtr;
        }
        else if (checkingPtr==NULL){
            return NULL;
        }
        else{
            currentAcPtr=checkingPtr->listAccountPtr;
            checkingPtr=checkingPtr->nextNodePtr;
        }
    }
}

//MAIN FUNCTION
int main(void){
    savingsLL* savingsHead=NULL;
    checkingLL* checkingHead=NULL;
    while (true){
        std::cout<<"THE MENU OPTIONS ARE\n"
                 <<"1. Open Account (Savings or Checking Account)\n"
                 <<"2. Credit (Savings or Checking Account)\n"
                 <<"3. Debit (Savings or Checking Account)\n"
                 <<"4. Change/Update Interest rate (Savings Account)\n"
                 <<"5. Calculate Interest (Savings Account - Print)\n"
                 <<"6. Calculate and Update Interest (Savings Account - Credit)\n"
                 <<"7. Change/Update Fee Amount (Checking Account)\n"
                 <<"8. Print Checking Fee (Checking Account)\n"
                 <<"9. Transact and Update (Checking Account - Debit)\n"
                 <<"10. Exit\n";
        int menuOption;
        std::cout<<"PLEASE ENTER THE REQUIRED OPTION\n";
        std::cin>>menuOption;
        if(menuOption==1){
            int internalMenu;
            std::cout<<"PLEASE ENTER THE 1 TO OPEN SAVINGS ACCOUNT,2 FOR CHECKING ACCOUNT\n";
            std::cin>>internalMenu;
            if(internalMenu==1){
                std::cout<<"PLEASE ENTER THE ACCOUNT NUMBER\n";
                int accountNumber;
                std::cin>>accountNumber;
                std::cout<<"PLEASE ENTER THE INITIAL BALANCE\n";
                double balance;
                std::cin>>balance;
                std::cout<<"PLEASE ENTER THE INTEREST RATE DIVIDED BY 100 I.E 0.03 FOR 3 PERCENT\n";
                double interest;
                std::cin>>interest;
                if(savingsHead==NULL){
                    savingsHead=new savingsLL;
                    savingsAccount reqAccount(balance,accountNumber,interest);
                    savingsHead->listAccountPtr=&reqAccount;
                    savingsHead->nextNodePtr=NULL;
                }
                else{
                    if(findAccount(accountNumber,savingsHead)){
                        std::cout<<"SAVINGS ACCOUNT ALREADY EXISTS\n";
                    }
                    else{
                        savingsLL *currentNodePtr = savingsHead->nextNodePtr;
                        savingsLL *prevNodePtr = savingsHead;
                        while (currentNodePtr != NULL) {
                            prevNodePtr = currentNodePtr;
                            currentNodePtr = currentNodePtr->nextNodePtr;
                        }
                        savingsAccount reqObject(balance, accountNumber, interest);
                        savingsAccount *reqPointer = new savingsAccount;
                        *reqPointer = reqObject;
                        currentNodePtr = new savingsLL;
                        currentNodePtr->listAccountPtr = reqPointer;
                        currentNodePtr->nextNodePtr = NULL;
                        prevNodePtr->nextNodePtr = currentNodePtr;
                    }
                }
            }
            else if(internalMenu==2){
                std::cout<<"PLEASE ENTER THE ACCOUNT NUMBER\n";
                int accountNumber;
                std::cin>>accountNumber;
                std::cout<<"PLEASE ENTER THE INITIAL BALANCE\n";
                double balance;
                std::cin>>balance;
                std::cout<<"PLEASE ENTER THE CHECKING FEES\n";
                double fee;
                std::cin>>fee;
                if(checkingHead==NULL){
                    checkingHead=new checkingLL;
                    checkingAccount reqAccount(balance,accountNumber,fee);
                    checkingHead->listAccountPtr=&reqAccount;
                    checkingHead->nextNodePtr=NULL;
                }
                else{
                    if(findAccount(accountNumber,checkingHead)){
                        std::cout<<"CHECKING ACCOUNT ALREADY EXISTS\n";
                    }
                    else {
                        checkingLL *currentNodePtr = checkingHead->nextNodePtr;
                        checkingLL *prevNodePtr = checkingHead;
                        while (currentNodePtr != NULL) {
                            prevNodePtr = currentNodePtr;
                            currentNodePtr = currentNodePtr->nextNodePtr;
                        }
                        checkingAccount reqObject(balance, accountNumber, fee);
                        checkingAccount *reqPtr = new checkingAccount;
                        *reqPtr = reqObject;
                        currentNodePtr = new checkingLL;
                        currentNodePtr->listAccountPtr = reqPtr;
                        currentNodePtr->nextNodePtr = NULL;
                        prevNodePtr->nextNodePtr = currentNodePtr;
                    }


                }
            }
            else{
                std::cout<<"PLEASE ENTER THE CORRECT OPTION\n";
            }

        }
        else if(menuOption==2){
            int internalMenu;
            std::cout<<"PLEASE ENTER 1 TO CREDIT TO SAVINGS ACCOUNT,2 TO CHECKING ACCOUNT\n";
            std::cin>>internalMenu;
            if(internalMenu==1){
                std::cout<<"PLEASE ENTER THE ACCOUNT NUMBER\n";
                int accountNumber;
                std::cin>>accountNumber;
                savingsAccount* account=NULL;
                if(savingsHead!=NULL){
                    account=findAccount(accountNumber,savingsHead);
                }
                else{
                    std::cout<<"NO SAVINGS ACCOUNTS EXIST\n";
                }
                if(account==NULL){
                    std::cout<<"ACCOUNT NOT FOUND\n";
                }
                else{
                    std::cout<<"PLEASE ENTER THE AMOUNT TO BE CREDITED\n";
                    double credit;
                    std::cin>>credit;
                    account->credit(credit);
                    std::cout<<"AMOUNT CREDITED\n";
                    std::cout<<"THE ACCOUNT BALANCE IS "<<account->getBalance()<<"\n";
                }
            }
            else if(internalMenu==2){
                std::cout<<"PLEASE ENTER THE ACCOUNT NUMBER\n";
                int accountNumber;
                std::cin>>accountNumber;
                checkingAccount* account=NULL;
                if(checkingHead!=NULL){
                    account=findAccount(accountNumber,checkingHead);
                }
                else{
                    std::cout<<"NO CHECKING ACCOUNTS EXIST\n";
                }
                if(account==NULL){
                    std::cout<<"ACCOUNT NOT FOUND\n";
                }
                else{
                    std::cout<<"PLEASE ENTER THE AMOUNT TO BE CREDITED\n";
                    double credit;
                    std::cin>>credit;
                    account->credit(credit);
                    std::cout<<"AMOUNT CREDITED\n";
                    std::cout<<"THE ACCOUNT BALANCE IS "<<account->getBalance()<<"\n";
                }
            }
            else{
                std::cout<<"PLEASE ENTER THE CORRECT OPTION\n";
            }

        }
        else if(menuOption==3){
            int internalMenu;
            std::cout<<"PLEASE ENTER 1 TO DEBIT FROM SAVINGS ACCOUNT,2 FROM CHECKING ACCOUNT\n";
            std::cin>>internalMenu;
            if(internalMenu==1){
                std::cout<<"PLEASE ENTER THE ACCOUNT NUMBER\n";
                int accountNumber;
                std::cin>>accountNumber;
                savingsAccount* account=NULL;
                if(savingsHead!=NULL){
                    account=findAccount(accountNumber,savingsHead);
                }
                else{
                    std::cout<<"NO SAVINGS ACCOUNTS EXIST\n";
                }
                if(account==NULL){
                    std::cout<<"ACCOUNT NOT FOUND\n";
                }
                else{
                    std::cout<<"PLEASE ENTER THE AMOUNT TO BE DEBITED\n";
                    double debit;
                    std::cin>>debit;
                    if(account->debit(debit)) {
                        std::cout << "AMOUNT DEBITED\n";
                        std::cout << "THE ACCOUNT BALANCE IS " << account->getBalance()<<"\n";
                    }
                }
            }
            else if(internalMenu==2){
                std::cout<<"PLEASE ENTER THE ACCOUNT NUMBER\n";
                int accountNumber;
                std::cin>>accountNumber;
                checkingAccount* account=NULL;
                if(checkingHead!=NULL){
                    account=findAccount(accountNumber,checkingHead);
                }
                else{
                    std::cout<<"NO CHECKING ACCOUNTS EXIST\n";
                }
                if(account==NULL){
                    std::cout<<"ACCOUNT NOT FOUND\n";
                }
                else{
                    std::cout<<"PLEASE ENTER THE AMOUNT TO BE DEBITED\n";
                    double debit;
                    std::cin>>debit;
                    if(account->debit(debit)){
                        std::cout<<"AMOUNT DEBITED\n";
                        std::cout<<"THE ACCOUNT BALANCE IS "<<account->getBalance()<<"\n";
                    }
                }
            }
            else{
                std::cout<<"PLEASE ENTER THE CORRECT OPTION\n";
            }

        }
        else if(menuOption==4){
            std::cout<<"PLEASE ENTER THE ACCOUNT NUMBER\n";
            int accountNumber;
            std::cin>>accountNumber;
            savingsAccount* account=NULL;
            if(savingsHead!=NULL){
                account=findAccount(accountNumber,savingsHead);
            }
            else{
                std::cout<<"NO SAVINGS ACCOUNTS EXIST\n";
            }
            if(account==NULL){
                std::cout<<"ACCOUNT NOT FOUND\n";
            }
            else{
                std::cout<<"PLEASE ENTER THE NEW INTEREST RATE IN THE FORM ENTERED ABOVE\n";
                double interest;
                std::cin>>interest;
                account->setInterest(interest);
            }
        }
        else if(menuOption==5){
            std::cout<<"PLEASE ENTER THE ACCOUNT NUMBER\n";
            int accountNumber;
            std::cin>>accountNumber;
            savingsAccount* account=NULL;
            if(savingsHead!=NULL){
                account=findAccount(accountNumber,savingsHead);
            }
            else{
                std::cout<<"NO SAVINGS ACCOUNTS EXIST\n";
            }
            if(account==NULL){
                std::cout<<"ACCOUNT NOT FOUND\n";
            }
            else{
                std::cout<<"THE INTEREST IS "<<account->calculateInterest()<<"\n";
            }

        }
        else if(menuOption==6){
            std::cout<<"PLEASE ENTER THE ACCOUNT NUMBER\n";
            int accountNumber;
            std::cin>>accountNumber;
            savingsAccount* account=NULL;
            if(savingsHead!=NULL){
                account=findAccount(accountNumber,savingsHead);
            }
            else{
                std::cout<<"NO SAVINGS ACCOUNTS EXIST\n";
            }
            if(account==NULL){
                std::cout<<"ACCOUNT NOT FOUND\n";
            }
            else{
                std::cout<<"THE INTEREST IS "<<account->calculateInterest()<<"\n";
                account->credit(account->calculateInterest());
                std::cout<<"THE ACCOUNT BALANCE IS "<<account->getBalance()<<"\n";
            }

        }
        else if(menuOption==7){
            std::cout<<"PLEASE ENTER THE ACCOUNT NUMBER\n";
            int accountNumber;
            std::cin>>accountNumber;
            checkingAccount* account=NULL;
            if(checkingHead!=NULL){
                account=findAccount(accountNumber,checkingHead);
            }
            else{
                std::cout<<"NO CHECKING ACCOUNTS EXIST\n";
            }
            if(account==NULL){
                std::cout<<"ACCOUNT NOT FOUND\n";
            }
            else{
                std::cout<<"PLEASE ENTER THE NEW CHECKING FEE\n";
                double fee;
                std::cin>>fee;
                account->setFee(fee);
            }

        }
        else if(menuOption==8){
            std::cout<<"PLEASE ENTER THE ACCOUNT NUMBER\n";
            int accountNumber;
            std::cin>>accountNumber;
            checkingAccount* account=NULL;
            if(checkingHead!=NULL){
                account=findAccount(accountNumber,checkingHead);
            }
            else{
                std::cout<<"NO CHECKING ACCOUNTS EXIST\n";
            }
            if(account==NULL){
                std::cout<<"ACCOUNT NOT FOUND\n";
            }
            else{
                std::cout<<"THE CHECKING FEE IS "<<account->getFee()<<"\n";
            }

        }
        else if(menuOption==9){
            std::cout<<"PLEASE ENTER THE ACCOUNT NUMBER\n";
            int accountNumber;
            std::cin>>accountNumber;
            checkingAccount* account=NULL;
            if(checkingHead!=NULL){
                account=findAccount(accountNumber,checkingHead);
            }
            else{
                std::cout<<"NO CHECKING ACCOUNTS EXIST\n";
            }
            if(account==NULL){
                std::cout<<"ACCOUNT NOT FOUND\n";
            }
            else{
                std::cout<<"THE CHECKING FEE IS "<<account->getFee()<<"\n";
                account->debitFee();
                std::cout<<"THE ACCOUNT BALANCE IS "<<account->getBalance()<<"\n";
            }

        }
        else if(menuOption==10){
            std::cout<<"GOODBYE\n";
            break;
        }
        else{
            std::cout<<"PLEASE ENTER A PROPER MENU OPTION\n";
        }
    }
}

