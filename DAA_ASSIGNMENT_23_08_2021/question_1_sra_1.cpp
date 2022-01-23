#include <iostream>
#include <vector>
class rain_water{
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
    void trappingRainwater(){
        int l=-1,r;
        int trappedRainWater=0;
        std::vector<int> trappingArray;
        for (int i = 0; i < mainArray.size(); ++i) {
            if(l==-1 && mainArray[i]>0){
               l=i;
            }

            if(mainArray[l]>mainArray[i] && i!=mainArray.size()-1 && l!=-1){
                trappingArray.push_back(mainArray[i]);
            }
            else{
                r=i;
                if(mainArray[l]<=mainArray[r]){
                    while(trappingArray.size()!=0){
                        trappedRainWater+=(mainArray[l]-trappingArray[trappingArray.size()-1]);
                        trappingArray.pop_back();
                    }
                }
                else if(mainArray[l]>mainArray[r] && r==mainArray.size()-1){
                    while(trappingArray.size()!=0)
                        trappingArray.pop_back();
                    int r1=-1,l1;
                    for (int j = mainArray.size()-1; j >=l ; j-=1) {
                        if(r1==-1 && mainArray[j]>0)
                            r1=j;
                        if(mainArray[r1]>mainArray[j] && r1!=-1)
                            trappingArray.push_back(mainArray[j]);
                        else{
                            l1=j;
                            while(trappingArray.size()!=0){
                                trappedRainWater+=(mainArray[r1]-trappingArray[trappingArray.size()-1]);
                                trappingArray.pop_back();
                            }
                        }
                        r1=l1;
                    }
                }
                l=r;

            }
        }
        std::cout<<"THE TRAPPED RAIN WATER IS: " << trappedRainWater  << "\n";
    }

};
int main(void){
    std::cout  << "PLEASE ENTER THE ELEMENTS IN THE ARRAY\n";
    rain_water requiredArray;
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
    requiredArray.trappingRainwater();

}