#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    void left_sub(Node* root, vector<int>&ans)
    {
        if(!root || (!root->left && !root->right))
            return;
        
        ans.push_back(root->data);
        
        if(root->left)
            left_sub(root->left, ans);
        else
            left_sub(root->right, ans);
    }

    void leaf_sub(Node *root, vector<int>&ans)
    {
        if(!root)
            return;

        if(!root->left && !root->right)
        {
            ans.push_back(root->data);
            return;
        }

        leaf_sub(root->left, ans);
        leaf_sub(root->right, ans);
    }

    void right_sub(Node *root, vector<int>&ans)
    {
        if(!root || (!root->left && !root->right))
            return;

        if(root->right)
            right_sub(root->right, ans);
        else
            right_sub(root->left, ans);
        
        ans.push_back(root->data);  
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;

        if(!root) return ans;

        ans.push_back(root->data);

        left_sub(root->left, ans);

        if(root->left || root->right)
            leaf_sub(root, ans);

        right_sub(root->right, ans);

        return ans; 
    }
};

int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    vector<int> result = obj.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}