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

class Solution {
  public:
    void find(Node *root,int &prev_val,bool &ans)
    {
        if(!root || !ans)
            return;
        
        find(root->left, prev_val, ans);
        
        if(prev_val >= root->data)
        {
            ans = 0;
            return;
        }
        
        prev_val = root->data;
        find(root->right, prev_val, ans);
    }

    bool isBST(Node* root) {
        int prev_val = INT_MIN;
        bool ans = 1;
        find(root, prev_val, ans);
        return ans;
    }
};

int main() {
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

    Solution obj;

    if(obj.isBST(root))
        cout << "The tree is a BST" << endl;
    else
        cout << "The tree is NOT a BST" << endl;

    return 0;
}