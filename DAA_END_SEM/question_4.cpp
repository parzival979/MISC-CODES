// PROGRAM BY SRAVANTH CHOWDARY POTLURI,CS20B1006
#include <bits/stdc++.h>
using namespace std;

class Knapsack{
private:
    vector<int>weightArray;
    vector<int>valueArray;
public:
    void arrayEntry(int data1, int data2){
        weightArray.push_back(data1);
        valueArray.push_back(data2);
    }
    int max(int a, int b){
        return (a > b) ? a : b;
    }
    void Display(){
        cout<<"The given weight array of objects is \n";
        for(int i=0; i<weightArray.size(); i++){
            cout<<weightArray[i]<< " ";
        }
        cout<<"\n";
        cout<<"The given Value of objects array is \n";
        for(int i=0; i<valueArray.size(); i++){
            cout<<valueArray[i]<< " ";
        }
        cout<<"\n";
    }
    int knapSack(int W){
        int n = weightArray.size();
        // Mapping weights with Profits
        map<int, int> umap;
        // A set for maintaining the solutions.
        set<vector<pair<int, int>>> set_sol;
        // Making Pairs and inserting into the map
        for (int i = 0; i < n; i++) {
            umap.insert({ weightArray[i], valueArray[i] });
        }
        int result = INT_MIN;
        int remaining_weight;
        int sum = 0;
        // Loop to iterate over all the possible permutations of array
        do {
            sum = 0;
            // Initially bag will be empty
            remaining_weight = W;
            vector<pair<int, int>> possible;
            // Loop to fill up the bag until there is no weight which is less than remaining weight of the knapSack
            for (int i = 0; i < n; i++) {
                if (weightArray[i] <= remaining_weight) {
                    remaining_weight -= weightArray[i];
                    auto itr = umap.find(weightArray[i]);
                    sum += (itr->second);
                    possible.push_back({itr->first,itr->second});
                }
            }
            sort(possible.begin(), possible.end());
            if (sum > result) {
                result = sum;
            }
            if (set_sol.find(possible) == set_sol.end()){
                for (auto sol: possible){
                    cout << sol.first << ": " << sol.second << ", ";
                }
                cout << endl;
                set_sol.insert(possible);
            }

        } while (next_permutation(weightArray.begin(), weightArray.end()));
        cout<<"The Number of Feasible Solutions are: "<<set_sol.size()<<"\n";
        return result;
    }

};

int main(){
    Knapsack object;
    int size, value, weight, max_weight;
    cout<<"Enter the size of the objects array:";
    cin>>size;
    for(int i = 0; i < size; i++){
        cout<<"Enter the weight and value of the object: ";
        cin >> weight >> value;
        object.arrayEntry(weight, value);
    }
    cout<<"Enter the maximum weight of the Knapsack:";
    cin>>max_weight;
    object.Display();
    int result = object.knapSack(max_weight);
    cout<<"The maximum profit is: "<<result<<"\n";
    return 0;
}