#include <iostream>
#include <vector>
class sub_arrays{
private:
    std::vector<int> mainArray;
public:
    void arrayEntry(int element){
       mainArray.push_back(element);
    };
    void array_printer(){
        for (int i = 0; i < mainArray.size(); ++i) {
            std::cout<<mainArray[i]<<" ";
        }
    }
    void sumSubArrays(){
        int totalSum=0;
        for (int i = 0; i < mainArray.size(); ++i) {
            for (int j = 0; j+i < mainArray.size() ; ++j){
                int sum=0;
                std::cout<<"[";
                for (int k = j; k-j <= i ; ++k) {
                    sum+=mainArray[k];
                    std::cout<<mainArray[k]<<",";
                }
                totalSum+=sum;
                std::cout<<"] THE SUM IS " <<sum<<"\n";
            }
        }
        std::cout<<"THE TOTAL SUM OF ALL THE SUB ARRAYS IS "<<totalSum<<"\n";
    }
};
int main(void){
    std::cout  << "PLEASE ENTER THE ELEMENTS IN THE ARRAY\n";
    sub_arrays requiredArray;
    int elements_entry = 1;
    while(elements_entry){
        if(elements_entry ==1){
            std::cout<<"PLEASE ENTER THE ELEMENT FOR THE ARRAY\n";
            int arrayElement;
            std::cin>>arrayElement;
            std::cout<<"\n";
            requiredArray.arrayEntry(arrayElement);
        }
        else{
            std::cout<<"Please choose an valid operation.\n";
        }
        std::cout<<"ENTER 1 IF YOU WANT ADD MORE ELSE 0\n";
        std::cin>>elements_entry;
    }
    std::cout<<"THE FINAL ARRAY IS\n";
    requiredArray.array_printer();
    std::cout<<"\n";
    std::cout<<"THE SUB ARRAYS ARE\n";
    requiredArray.sumSubArrays();

}