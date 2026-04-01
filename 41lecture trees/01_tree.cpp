#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left =NULL;
        right =NULL;
    }
};
Node* BinaryTree()
{
    int x;
    cout<<"enter the value:";
    cin>>x;
    if(x==-1)
    return NULL;

    Node *root =new Node(x);
    cout<<"enter the left child of "<<"\n";
    root->left =BinaryTree();
    cout<<"enter the right child of "<<"\n";
    root->right =BinaryTree();
    return root;
}
int main()
{
    Node *root = BinaryTree();
    return 0;
}