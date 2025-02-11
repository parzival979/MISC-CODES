#include<iostream>

//FUNCTION PROTOTYPES
template<typename t>
void selectionSort(t array[],int nos);

template<typename q>
void swap(q &a,q &b);

template<typename t>
void displayArray(t array[],int nos);

//MAIN FUNCTION
int main(void){
    //DECLARING THE REQUIRED VARIABLES AND ARRAYS
    int* intArray=NULL;
    double* doubleArray=NULL;
    char* charArray=NULL;
    int arraySize=0;
    while(true){
        //MENU FOR THE PROGRAM FUNCTIONALITY
        std::cout << "PLEASE CHOOSE YOUR MENU OPTION\n";
        std::cout << "1.Get Values\n"
                     "2.Sort\n"
                     "3.Display\n"
                     "4.Exit\n";

        int menuOption;
        std::cin >> menuOption;
        //MENU OPTION TO TAKE THE ELEMENTS INTO THE ARRAY
        if(menuOption == 1){
            intArray=NULL;
            doubleArray=NULL;
            charArray=NULL;
            arraySize=0;
            int internalMenu;
            std::cout<<"PLEASE ENTER 1 FOR ARRAY OF INTEGERS,2 FOR ARRAY OF DOUBLES OR 3 FOR ARRAY OF CHARACTERS\n";
            std::cin>>internalMenu;
            std::cout<<"PLEASE ENTER THE SIZE OF THE ARRAY\n";
            std::cin>>arraySize;
            //EXCEPTION HANDLING IF THE ARRAY SIZE IS NEGATIVE
            try{
                if(arraySize<=0){
                    throw arraySize;
                }
            }
            catch (int){
                std::cout<<"INVALID ARRAY SIZE\n";
                std::cout<<"PLEASE TRY INSERTING AGAIN\n";
                continue;
            }
            if(internalMenu==1){
                intArray=new int[arraySize];
                for (int i = 0; i < arraySize; ++i){
                    std::cout<<"PLEASE ENTER THE ELEMENT "<<i<<" OF THE ARRAY\n";
                    std::cin>>intArray[i];
                }
            }
            else if(internalMenu==2){
                doubleArray=new double[arraySize];
                for (int i = 0; i < arraySize; ++i){
                    std::cout<<"PLEASE ENTER THE ELEMENT "<<i<<" OF THE ARRAY\n";
                    std::cin>>doubleArray[i];
                }
            }
            else if(internalMenu==3){
                charArray=new char[arraySize];
                for (int i = 0; i < arraySize; ++i){
                    std::cout<<"PLEASE ENTER THE ELEMENT "<<i<<" OF THE ARRAY\n";
                    std::cin>>charArray[i];
                }
            }
            else{
                std::cout<<"PLEASE CHOOSE A VALID MENU OPTION\n";
                continue;
            }
        }
        //MENU OPTION TO SORT THE ELEMENTS
        else if(menuOption == 2){
            if(intArray!=NULL){
                selectionSort(intArray,arraySize);
            }
            else if(doubleArray!=NULL){
                selectionSort(doubleArray,arraySize);
            }
            else if(charArray!=NULL){
                selectionSort(charArray,arraySize);
            }
            else{
                std::cout<<"PLEASE INSERT THE ELEMENTS FIRST\n";
            }
        }
        //MENU OPTION TO DISPLAY THE ARRAY
        else if(menuOption == 3){
            if(intArray!=NULL){
                std::cout<<"THE ARRAY IS\n";
                displayArray(intArray,arraySize);
            }
            else if(doubleArray!=NULL){
                std::cout<<"THE ARRAY IS\n";
                displayArray(doubleArray,arraySize);
            }
            else if(charArray!=NULL){
                std::cout<<"THE ARRAY IS\n";
                displayArray(charArray,arraySize);
            }
            else{
                std::cout<<"PLEASE INSERT THE ELEMENTS FIRST\n";
            }
        }
        else if(menuOption == 4){
            std::cout << "GOODBYE\n";
            break;
        }
        else{
            std::cout << "PLEASE CHOOSE A VALID MENU OPTION\n";
        }
    }

}

//FUNCTION DEFINITION FOR SELECTION SORT
template<typename t>
void selectionSort(t array[],int nos){
    for (int j = 0; j < nos-1; ++j) {
        int min = j;
        for (int i = j+1; i < nos ; ++i) {
            if(array[i]<array[min])
                min=i;
        }
        swap(array[j],array[min]);
    }
}

//FUNCTION DEFINITION FOR SWAPPING ELEMENTS
template<typename q>
void swap(q &a,q &b){
    q temp = b;
    b=a;
    a=temp;
}

//FUNCTION DEFINITION FOR DISPLAYING THE ARRAY
template<typename t>
void displayArray(t array[],int nos){
    for (int i = 0; i < nos; ++i) {
        std::cout<<array[i]<<" ";
    }
    std::cout<<"\n";
}
