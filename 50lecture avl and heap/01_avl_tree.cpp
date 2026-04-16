#include<iostream>
#include<algorithm>
using namespace std;

class Node
{
    public:
    int data,height;
    Node *left,*right;
    Node(int value)
    {
        data=value;
        height=1;
        left=right=NULL;
    }
};

int getHeight(Node *root)
{
    if(!root)
        return 0;

    return root->height;
}

void updateHeight(Node *root)
{
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    root->height = 1 + max(leftHeight, rightHeight);
}

Node * rotateRight(Node *root)
{
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;

    updateHeight(root);
    updateHeight(temp);

    return temp;
}

Node * rotateLeft(Node *root)
{
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;

    updateHeight(root);
    updateHeight(temp);

    return temp;
}

Node * Balance(Node *root)
{
    if(!root)
        return NULL;

    updateHeight(root);

    int balance = getHeight(root->left) - getHeight(root->right);

    // Left Left Case
    if(balance > 1)
    {
        if(getHeight(root->left->left) >= getHeight(root->left->right))
        {
            return rotateRight(root);
        }
        // Left Right Case
        else
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }  

    // Right Right Case
    else if(balance < -1)
    {
        if(getHeight(root->right->right) >= getHeight(root->right->left))
        {
            return rotateLeft(root);
        }
        // Right Left Case
        else
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

void inorder(Node *root)
{
    if(!root)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if(!root)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

Node * insert(Node *root,int value)
{
    if(!root)
        return new Node(value);

    if(value < root->data)
        root->left = insert(root->left,value);
    else if(value > root->data)
        root->right = insert(root->right,value);
    else
        return root;

    return Balance(root);
}
int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    return 0;
}