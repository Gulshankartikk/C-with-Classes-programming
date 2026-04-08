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

// ✅ Add this function (missing)
Node * BST(Node *root, int value)
{
    if(!root)
        return new Node(value);

    if(root->data > value)
        root->left = BST(root->left, value);
    else
        root->right = BST(root->right, value);

    return root;
}

class Solution {
  public:
    bool search(Node* root, int key) {
        if(!root)
            return 0;
        
        if(root->data == key)
            return 1;
        
        if(root->data > key)
            return search(root->left, key);
        else
            return search(root->right, key);

        return 0; // ✅ safety (not strictly needed but good practice)
    }
};

int main()
{
    int arr[10]={10,13,4,8,11,19,2,7,18,23};
    Node *root =NULL;
    
    for(int i=0;i<10;i++)
        root = BST(root, arr[i]);

    Solution sol;
    int key = 7;

    if(sol.search(root,key))
        cout << "Key " << key << " found in the BST." << endl;
    else
        cout << "Key " << key << " not found in the BST." << endl;

    return 0;
}