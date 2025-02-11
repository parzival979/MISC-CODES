#include <iostream>
#include <vector>

using namespace std;

class OptimalBinarySearch{
private:
    vector <int> keys;
    vector <int> freq;
public:
    void add(int b, int c){
        keys.push_back(b);
        freq.push_back(c);
    }

    int optimalSearchTree(int n){
        int cost[n][n];
        for (int i = 0; i < n; i++)
            cost[i][i] = freq[i];
        for (int L = 2; L <= n; L++)
        {
            for (int i = 0; i <= n-L+1; i++)
            {
                int j = i+L-1;
                cost[i][j] = INT_MAX;
                for (int r = i; r <= j; r++)
                {
                int c = ((r > i)? cost[i][r-1]:0) +
                        ((r < j)? cost[r+1][j]:0) +
                        sum(i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
                }
            }
	    }
	return cost[0][n-1];
    }

    int sum(int i, int j){
        int s = 0;
        for (int k = i; k <= j; k++)
        s += freq[k];
        return s;
    }

};

int main()
{
	OptimalBinarySearch obj;
    int size,x,y;
    cout<<"Enter the number of keys: ";
    cin>>size;
    cout<<"Enter the keys and their frequency:\n";
    for(int i=0;i<size;i++){
        cin>>x;
        cin>>y;
        obj.add(x,y);
    }
    cout<<endl;
	cout << "Cost of Optimal BST is " << obj.optimalSearchTree(size);
	return 0;
}
