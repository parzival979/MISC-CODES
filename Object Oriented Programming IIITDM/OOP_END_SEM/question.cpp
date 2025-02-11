// PROGRAMMED BY CS20B1006 SRAVANTH CHOWDARY POTLURI
#include <iostream>
//REQUIRED CLASS
class details{
    //PRIVATE ATTRIBUTES OF THE CLASS
private:
    std::string text;
    float realValue;
    int intValue;
public:
    //REQUIRED CONSTRUCTORS
    details(){
        text="\0";
        realValue=0;
        intValue=0;
    }
    details(std::string reqText,float reqReal,int reqInt){
        text=reqText;
        realValue=reqReal;
        intValue=reqInt;
    }

    //MEMBER FUNCTION TO DISPLAY OBJECT
    void displayObject(){
        std::cout<<text<<" "<<realValue<<" "<<intValue<<"\n";
    }

    // OVERLOADING <= OPERATOR AS REQUIRED
    friend void operator <= (details &a,details &b){
        a.intValue=b.intValue;
        a.realValue=b.realValue;
    }

    // OVERLOADING / OPERATOR TO CHECK FOR SUBSTRING
    friend bool operator / (details &a,details&b){
        int M = b.text.length();
        int N = a.text.length();

        /* A loop to slide pat[] one by one */
        for (int i = 0; i <= N - M; i++) {
            int j;

            /* For current index i, check for
     pattern match */
            for (j = 0; j < M; j++)
                if (a.text[i + j] != b.text[j])
                    break;

            if (j == M)
                return true;
        }

        return false;

    }
};


int main(void){
    std::cout<<"PLEASE ENTER THE MAXIMUM NUMBER OF OBJECTS\n";
    int maxNos;
    std::cin>>maxNos;

    //EXCEPTION HANDLING
    try{
        if(maxNos<=0){
            throw false;
        }
        else{
            throw true;
        }
    }
    catch(bool x){
        if(!x){
            std::cout<<"MAXIMUM NUMBER OF OBJECTS CANNOT BE LESS THAN OR EQUAL TO 0\n";
            exit(0);
        }
    }

    //CREATING THE REQUIRED ARRAY OF OBJECTS
    details* arrayDetails = new details[maxNos];
    //COUNTER VARIABLE TO KEEP TRACK OF NUMBER OF OBJECTS ENTERED
    int lastObjNo=0;

    while(true){
        //MENU
        std::cout<<"PLEASE SELECT THE MENU OPTION\n";
        std::cout<<"(a) Enter details (create details object)\n"
                   "(b) Assign detail values\n"
                   "(c) Check substring or not\n"
                   "(d) Display all the objects\n"
                   "(e) Exit.\n";
        char menuOption;
        std::cin>>menuOption;
        if(menuOption=='a'){
            //EXCEPTION HANDLING
            try{
                if(lastObjNo>=maxNos){
                    throw false;
                }
                else{
                    throw true;
                }
            }
            catch(bool x){
                if(!x){
                    std::cout<<"OBJECTS ARRAY ALREADY FULL\n";
                    continue;
                }
            }

            std::cout<<"PLEASE ENTER THE DETAILS OF THE OBJECT\n";
            std::string reqText;
            float reqReal;
            int reqInt;
            std::cout<<"PLEASE ENTER THE STRING\n";
            std::cin>>reqText;
            std::cout<<"PLEASE ENTER THE FLOAT\n";
            std::cin>>reqReal;
            std::cout<<"PLEASE ENTER THE INTEGER\n";
            std::cin>>reqInt;
            //PARAMETERIZED CONSTRUCTOR TO INITIALIZE THE VALUES INTO THE OBJECT
            arrayDetails[lastObjNo]=details(reqText,reqReal,reqInt);
            lastObjNo+=1;
        }
        else if(menuOption=='b'){
            std::cout<<"PLEASE ENTER THE OBJECT POSITIONS FOR ASSIGNING\n";
            int a,b;
            std::cout<<"PLEASE ENTER THE OBJECT NUMBER TO ASSIGN FROM\n";
            std::cin>>a;
            std::cout<<"PLEASE ENTER THE OBJECT NUMBER TO ASSIGN THE VALUES TO\n";
            std::cin>>b;
            //EXCEPTION HANDLING
            try{
                if(a<0||a>=lastObjNo||b<0||b>=lastObjNo){
                    throw false;
                }
                else{
                    throw true;
                }
            }
            catch(bool x){
                if(!x){
                    std::cout<<"INVALID OBJECTS CHOSEN\n";
                    continue;
                }
            }
            //OVERLOADED FUNCTION TO ASSIGN THE VALUES
            arrayDetails[b]<=arrayDetails[a];
        }
        else if(menuOption=='c'){
            std::cout<<"PLEASE ENTER THE OBJECT NUMBER FROM WHICH TO CHECK FOR SUBSTRING\n";
            int number;
            std::cin>>number;
            //EXCEPTION HANDLING
            try{
                if(number<0||number>=lastObjNo){
                    throw false;
                }
                else{
                    throw true;
                }
            }
            catch(bool x){
                if(!x){
                    std::cout<<"INVALID OBJECT CHOSEN\n";
                    continue;
                }
            }
            //CHECKING IF SUBSTRING OF EVERY OBJECT
            for (int i = 0; i < lastObjNo; ++i) {
                if(i==number){
                    continue;
                }

                if(arrayDetails[i]/arrayDetails[number]){
                    std::cout<<"IS A SUBSTRING OF OBJECT "<<i<<"\n";
                }
                else{
                    std::cout<<"IS NOT A SUBSTRING OF OBJECT "<<i<<"\n";
                }
            }
        }

        else if(menuOption=='d'){
            //DISPLAYING ALL THE OBJECTS
            std::cout<<"THE OBJECTS ARE\n";
            for (int i = 0; i < lastObjNo; ++i){
                std::cout<<"OBJECT"<<i<<" ";
                arrayDetails[i].displayObject();
            }
        }
        //MENU OPTION TO EXIT
        else if(menuOption=='e'){
            std::cout<<"GOODBYE\n";
            break;
        }
        else{
            //EXCEPTION HANDLING
            try{
                throw false;
            }
            catch(bool x){
                if(!x){
                    std::cout<<"PLEASE CHOOSE A VALID OPTION\n";
                    continue;
                }
            }
        }

    }

}