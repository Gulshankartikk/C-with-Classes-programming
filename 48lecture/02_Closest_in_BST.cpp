#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to find the least absolute difference between any node
    // value of the BST and the given integer.
    int minDiff(Node *root, int K) {
        // Your code here
        if(!root)
        return INT_MAX;
        
        if(K==root->data)
        return 0;
        
        else if(K>root->data)
        return min(K-root->data,minDiff(root->right,K));
        
        else
        return min(root->data-K,minDiff(root->left,K));
    }
};
int main()
{
    /*
        Constructing this BST:
              4
             / \
            2   6
           / \ / \
          1  3 5  7
    */
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    Solution obj;
    int K = 8;
    cout << "Minimum difference: " << obj.minDiff(root, K) << endl;

    return 0;
}