#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;
    Node(int value)
    {
        data=value;
        left=right=NULL;
    }
};
Node *createBBST(vector<int>&v, int start,int end)
{
    if(start>end)
    return NULL;

    int mid=(start+end)/2;
    Node *root=new Node(v[mid]);
    root->left=createBBST(v,start,mid-1);
    root->right=createBBST(v,mid+1,end);
    return root;
}
void inorder(Node *root)
{
    if(!root)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
};
int main()
{
   //size of array
   int n;
   cin>>n;
   vector<int>v(n);
   for(int i=0;i<n;i++)
   cin>>v[i];
   
   //sort the array
   sort(v.begin(),v.end());
   Node *root = createBBST(v,0,n-1);
   inorder(root);
   return 0;
}