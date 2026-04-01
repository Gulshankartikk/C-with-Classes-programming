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
    cout<<"Enter value (-1 for NULL): ";
    cin>>x;

    if(x == -1)
        return NULL;

    Node *root = new Node(x);

    cout<<"Enter left child of "<<x<<":\n";
    root->left = BinaryTree();

    cout<<"Enter right child of "<<x<<":\n";
    root->right = BinaryTree();

    return root;
}
int main()
{
    Node *root = BinaryTree();
    return 0;
}