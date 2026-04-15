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
Node * rotateRight(Node *root)
{
    Node *temp =root->left;
    root->left =temp->right;
    temp->right =root;

    return temp;
}
Node * rotateLeft(Node *root)
{
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;

    return temp;
}

Node *insertBSt(Node *root,int value)
{
    if(!root)
    return new Node(value);

    if(value<root->data)
    root->left = insertBSt(root->left,value);
    else if(value>root->data)
    root->right = insertBSt(root->right,value);
    else
    return root;

    root->height = 1+max(getHeight(root->left),getHeight(root->right));

    int balance = getHeight(root->left)-getHeight(root->right);

    // Left Left Case
    if(balance>1 && value<root->left->data)
    return rotateRight(root);

    // Right Right Case
    if(balance<-1 && value>root->right->data)
    return rotateLeft(root);

    // Left Right Case
    if(balance>1 && value>root->left->data)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Left Case
    if(balance<-1 && value<root->right->data)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

int main()
{
    Node *root =NULL;
    int value;
    while(1)
    {
        cin>>value;
        if(value!=-1)
        root =insertBSt(root,value);
        else
        break;
    }

}