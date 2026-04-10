#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
void find(Node *root, int &k,int &total)
{
    if(!root || k<0)
    return;
    
    find(root->left,k,total);
    k--;
    
    if(k>=0)
    total+=root->data;
    
    find(root->right,k,total);
}
int sum(Node* root, int k) {

    // Your code here
    int total =0;
    find(root ,k,total);
    return total;
}

int main()
{
    /*
        Constructing this tree:
                4
               / \
              2   5
             / \
            1   3
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
}