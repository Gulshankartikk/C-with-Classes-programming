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
void Inorder(Node *root)
{
    if(root==NULL)
    return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
    return;
}
void Postorder(Node *root)
{
    if(root==NULL)
    return;

    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
    return;
}
void Preorder(Node *root)
{
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
    return;
}
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
    cout<<"Inorder Traversal: ";
    Inorder(root);
    cout<<endl;
    cout<<"\nPreorder Traversal: ";
    Preorder(root);
    cout<<endl;
    cout<<"\nPostorder Traversal: ";
    Postorder(root); 
    cout<<endl;
    return 0;
}