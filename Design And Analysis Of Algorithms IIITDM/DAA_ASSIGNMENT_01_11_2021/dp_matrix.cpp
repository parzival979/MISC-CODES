#include<iostream>
#include<vector>

using namespace std;

class matrix{
private:
    vector <int> a;

public:
    void add(int b){
        a.push_back(b);
    }
    
    int MatrixChainOrder(int n){
        int m[n][n];
        int j,q;

        for (int i = 1; i < n; i++)
            m[i][i] = 0;

        for (int L = 1; L < n-1; L++){
            for (int i = 1; i < n - L ; i++){
                j = i + L;
                m[i][j] = INT_MAX;
                
        
                for (int k = i; k <= j - 1; k++){
                    q = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j];
                    
                    if (q < m[i][j])
                        m[i][j] = q;
                    }
            }
        }

        return m[1][n - 1];
    }
};


int main()
{
    matrix obj;
    int size,x;
    cout<<"Enter the size of the order array: ";
    cin>>size;
    cout<<"Enter elements into the array: \n";

    for(int i=0;i<size;i++){
        cin>>x;
        obj.add(x);
    }
    cout<<endl;
	cout << "Cost of multiplications is: "<< obj.MatrixChainOrder(size);
	return 0;
}

