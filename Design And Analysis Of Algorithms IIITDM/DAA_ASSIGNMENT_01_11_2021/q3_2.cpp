#include<iostream>
#include<vector>
#include <cmath>
using namespace std;


void swap(int &i,int &j);
void swap(double &i,double &j);
double max(double x, double y);

template<typename t>
void printArray(std::vector<t> array);


void knapSack(int weight,vector<int> weightArray, vector<int> valueArray);
void knapSack(double weight,vector<double> weight_array, vector<double> value_array);
void knapSack(int weight,std::vector<int> array);
void knapSack(int weight,std::vector<int> weightArray,std::vector<int> profitArray,bool flag);



int main(){
    std::cout<<"PLEASE SELECT THE VARIANT OF THE KNAPSACK YOU REQUIRE\n";
    std::cout<<"1.Knapsack(int W, int Weight, int Profit)\n"
               "2.Knapsack(double W, double Weight, double Profit)\n"
               "3.Knapsack(int W, int Weight)\n"
               "4.Knapsack(int W, int Weight, int Profit, bool flag\n";
    int menuOption;
    std::cin>>menuOption;
    if(menuOption==1){
        int max_weight;
        std::vector<int> weight;
        std::vector<int> profit;
        std::cout<<"PLEASE ENTER THE MAXIMUM WEIGHT OF THE KNAPSACK\n";
        std::cin>>max_weight;
        while(true){
            std::cout<<"ENTER 1 IF YOU WANT TO ENTER AN ITEM ELSE 0 TO COMPUTE\n";
            int internalMenuOption;
            std::cin>>internalMenuOption;
            if(internalMenuOption==1){
                std::cout<<"PLEASE ENTER THE WEIGHT OF THE ITEM\n";
                int itemWeight;
                std::cin>>itemWeight;
                weight.push_back(itemWeight);
                std::cout<<"PLEASE ENTER THE PROFIT OF THE ITEM\n";
                int itemProfit;
                std::cin>>itemProfit;
                profit.push_back(itemProfit);
            }
            else if(internalMenuOption==0){
                std::cout<<"THE WEIGHT ARRAY IS\n";
                printArray(weight);
                std::cout<<"THE PROFIT ARRAY IS\n";
                printArray(profit);
                knapSack(max_weight,weight,profit);
                break;
            }
            else{
                std::cout<<"PLEASE CHOSE A VALID OPTION\n";
            }
        }

    }
    else if(menuOption==2){
        double max_weight;
        std::vector<double> weight;
        std::vector<double> profit;
        std::cout<<"PLEASE ENTER THE MAXIMUM WEIGHT OF THE KNAPSACK\n";
        std::cin>>max_weight;
        while(true){
            std::cout<<"ENTER 1 IF YOU WANT TO ENTER AN ITEM ELSE 0 TO COMPUTE\n";
            int internalMenuOption;
            std::cin>>internalMenuOption;
            if(internalMenuOption==1){
                std::cout<<"PLEASE ENTER THE WEIGHT OF THE ITEM\n";
                double itemWeight;
                std::cin>>itemWeight;
                weight.push_back(itemWeight);
                std::cout<<"PLEASE ENTER THE PROFIT OF THE ITEM\n";
                double itemProfit;
                std::cin>>itemProfit;
                profit.push_back(itemProfit);
            }
            else if(internalMenuOption==0){
                std::cout<<"THE WEIGHT ARRAY IS\n";
                printArray(weight);
                std::cout<<"THE PROFIT ARRAY IS\n";
                printArray(profit);
                knapSack(max_weight,weight,profit);
                break;
            }
            else{
                std::cout<<"PLEASE CHOSE A VALID OPTION\n";
            }
        }

    }
    else if(menuOption==3){
        int max_weight;
        std::vector<int> weight;
        std::cout<<"PLEASE ENTER THE MAXIMUM WEIGHT OF THE KNAPSACK\n";
        std::cin>>max_weight;
        while(true){
            std::cout<<"ENTER 1 IF YOU WANT TO ENTER AN ITEM ELSE 0 TO COMPUTE\n";
            int internalMenuOption;
            std::cin>>internalMenuOption;
            if(internalMenuOption==1){
                std::cout<<"PLEASE ENTER THE WEIGHT OF THE ITEM\n";
                int itemWeight;
                std::cin>>itemWeight;
                weight.push_back(itemWeight);
            }
            else if(internalMenuOption==0){
                std::cout<<"THE WEIGHT ARRAY IS\n";
                printArray(weight);
                knapSack(max_weight,weight);
                break;
            }
            else{
                std::cout<<"PLEASE CHOSE A VALID OPTION\n";
            }
        }

    }
    else if(menuOption == 4){
        int max_weight;
        std::vector<int> weight;
        std::vector<int> profit;
        std::cout<<"PLEASE ENTER THE MAXIMUM WEIGHT OF THE KNAPSACK\n";
        std::cin>>max_weight;
        while(true){
            std::cout<<"ENTER 1 IF YOU WANT TO ENTER AN ITEM ELSE 0 TO COMPUTE\n";
            int internalMenuOption;
            std::cin>>internalMenuOption;
            if(internalMenuOption==1){
                std::cout<<"PLEASE ENTER THE WEIGHT OF THE ITEM\n";
                int itemWeight;
                std::cin>>itemWeight;
                weight.push_back(itemWeight);
                std::cout<<"PLEASE ENTER THE PROFIT OF THE ITEM\n";
                int itemProfit;
                std::cin>>itemProfit;
                profit.push_back(itemProfit);
            }
            else if(internalMenuOption==0){
                std::cout<<"THE WEIGHT ARRAY IS\n";
                printArray(weight);
                std::cout<<"THE PROFIT ARRAY IS\n";
                printArray(profit);
                knapSack(max_weight,weight,profit,true);
                break;
            }
            else{
                std::cout<<"PLEASE CHOSE A VALID OPTION\n";
            }

    }
    }
    else{
        std::cout<<"INVALID OPTION ENTERED\n";
    }


}


void knapSack(int weight,vector<int> weightArray, vector<int> valueArray){
    int n = valueArray.size();
    int W = weight;
    int K[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weightArray[i - 1] <= w)
                K[i][w] = max(valueArray[i - 1] + K[i - 1][w - weightArray[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    int result = K[n][W];
    cout<<"The maximum total value is "<< result << " \n";
    cout<<"The weight of corresponding objects are: \n";
    int w = W;
    for (int i = n; i > 0 && result > 0; i--) {
        if (result == K[i - 1][w])
            continue;   
        else {
            cout<<" "<<weightArray[i - 1] ;
            result = result - valueArray[i - 1];
            w = w - weightArray[i - 1];
        }
    }
    cout<<"\n";
}

void knapSack(double weight,vector<double> weight_array, vector<double> value_array){
    int n = value_array.size();
    int W = ceil(weight);
    double K[n + 1][W + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 || j == 0){
                K[i][j] = 0;
            }
            else if(weight_array[i - 1] <= weight){
                K[i][j] = max(value_array[i - 1] + K[i - 1][j - (int)floor(weight_array[i - 1])], K[i - 1][j]);
            }
            else {
                K[i][j] = K[i - 1][j];
            }
        }
    }
    double result = K[n][W];
    int w = W;
    cout<<"The maximum total value is "<< result << " \n";
    cout<<"The weight of corresponding objects are: \n";
    for(int i = value_array.size(); i > 0 && result > 0; i--){
        if(result == K[i - 1][w]){
            continue;
        }
        else {
            cout<<weight_array[i - 1]<<" ";
            result = result - value_array[i - 1];
            w -= weight_array[i - 1];
        }
    }
    cout<<"\n";
}

void knapSack(int weight,std::vector<int> array){
    for(int i=0;i<array.size();i++)
    {
        if(i>0)
        {
            if(array[i]<array[i-1])
            {
                swap(array[i],array[i-1]);
                for(int j=i-1;(j>0)&&(array[j]<array[j-1]);j--)
                {
                    swap(array[j],array[j-1]);
                }
            }
        }
    }
    std::vector<int> selectedItems;
    for (int i = 0; i < array.size(); ++i) {
        if(array[i]<=weight){
            selectedItems.push_back(array[i]);
            weight-=array[i];
        }
        else{
            break;
        }
    }
    std::cout<<"THE SELECTED ITEMS ARE\n";
    printArray(selectedItems);
    std::cout<<"\n";

}

void knapSack(int weight,std::vector<int> weightArray,std::vector<int> profitArray,bool flag) {
    std::vector<double> weightByProfit;
    for (int i = 0; i < weightArray.size(); ++i) {
        weightByProfit.push_back((double)weightArray[i] / (double)profitArray[i]);
    }
    std::cout<<"THE WEIGHT BY PROFIT ARRAY IS\n";
    printArray(weightByProfit);
    for (int i = 0; i < weightByProfit.size(); i++) {
        if (i > 0) {
            if (weightByProfit[i] < weightByProfit[i - 1]) {
                swap(weightByProfit[i], weightByProfit[i - 1]);
                swap(weightArray[i], weightArray[i - 1]);
                swap(profitArray[i], profitArray[i - 1]);
                for (int j = i - 1; (j > 0) && (weightByProfit[j] < weightByProfit[j - 1]); j--) {
                    swap(weightByProfit[j], weightByProfit[j - 1]);
                    swap(weightArray[i], weightArray[i - 1]);
                    swap(profitArray[i], profitArray[i - 1]);
                }
            }
        }

    }
    std::cout<<"THE ARRAYS SORTER ACCORDING TO WEIGHT BY PROFIT ARE\n";
    std::cout<<"WEIGHT ARRAY\n";
    printArray(weightArray);
    std::cout<<"PROFIT ARRAY\n";
    printArray(profitArray);
    std::cout<<"WEIGHT BY PROFIT ARRAY\n";
    printArray(weightByProfit);
    std::vector<double> resultArray;
    for (int i = 0; i < weightByProfit.size(); ++i) {
        if(weightArray[i]<=weight){
            resultArray.push_back(1);
            weight-=weightArray[i];
        }
        else if(weightArray[i]>weight){
            resultArray.push_back((double)weight/(double)weightArray[i]);
            weight=0;
        }
    }
    std::cout<<"THE RESULT ARRAY IS\n";
    printArray(resultArray);
    std::cout<<"THE PROFIT GENERATED IS\n";
    double profitGenerated=0;
    for (int i = 0; i < resultArray.size(); ++i) {
        profitGenerated+=resultArray[i]*profitArray[i];
    }
    std::cout<<profitGenerated<<"\n";
}

void swap(int &i,int &j)
{
    int temp=i;
    i=j;
    j=temp;
}

void swap(double &i,double &j){
    double temp=i;
    i=j;
    j=temp;
}


template<typename t>
void printArray(std::vector<t> array){
    for (int i = 0; i < array.size(); ++i) {
        std::cout<<array[i]<<" ";
    }
    std::cout<<"\n";
}

double max(double x, double y){
    return (x > y) ? x : y;
}



