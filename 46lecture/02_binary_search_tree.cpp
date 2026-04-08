#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *left,*right;
    Node(int x)
    {
        data=x;
        left=right=NULL;
    };
};
Node * BST(Node *root, int value)
{
    if(!root)
    {
        root =new Node(value);
        return root;
    }//left side
    if(root->data>value)
    {
        root->left=BST(root->left,value);
        return root;
    }
    //right side
    else{
        root->right=BST(root->right,value);
        return root;
    }
    
}

int main()
{
    int arr[10]={10,13,4,8,11,19,2,7,18,23};
    Node *root =NULL;
    for(int i=0;i<10;i++)
    root =BST(root,arr[i]);
    return 0;
}