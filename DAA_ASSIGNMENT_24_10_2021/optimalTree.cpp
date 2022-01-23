#include<iostream>
#include<climits>
#include<queue>
using namespace std;
class tree
{
    private:
        int data,data1;
        tree* left,*right;
    public:
        tree* computation(int a[],int b[],int start,int end)
        {
            if(start>end)
            {
                return NULL;
            }
            int rootIndex,max=INT_MIN;
            for(int i=start;i<=end;i++)
            {
                if(max<b[i]) {rootIndex=i; max=b[i];}
            }
            tree* root=new tree;
            root->data=a[rootIndex]; root->data1=b[rootIndex];
            root->left=computation(a,b,start,rootIndex-1);
            root->right=computation(a,b,rootIndex+1,end);
            return root;
        }
        void printLevelOrder(tree *root)
        {
            int cost=0,level=1;
            if (root == NULL) return;
            queue<tree *> q;
            q.push(root);
            while (q.empty() == false)
            {
                int treeCount = q.size();
                cout<< "Level "<<level<<":";
                while (treeCount > 0)
                {
                    tree *tree = q.front();
                    cout <<tree->data << " ";
                    cost+=level*tree->data1;
                    q.pop();
                    if (tree->left != NULL)
                        q.push(tree->left);
                    if (tree->right != NULL)
                        q.push(tree->right);
                    treeCount--;
                }
                 level++; 
                cout << endl;
            }
            cout<<"The minimum cost of the BST is:"<<cost<<endl;
        }
};
int main()
{
    tree obj;
    int n;
    cout<<"Enter the number of keys:";
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the key and the frequency:";
        cin>>a[i]>>b[i];
    }
    tree* root=obj.computation(a,b,0,n-1);
    obj.printLevelOrder(root);

    return 0;
}