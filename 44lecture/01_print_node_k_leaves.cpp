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
    int find(Node *root, vector<int>&count, int k)
    {
        if(!root)
            return 0;
        
        if(!root->left && !root->right)
            return 1;
        
        int left = find(root->left, count, k);   
        int right = find(root->right, count, k);
        
        if(k == left + right)
            count.push_back(root->data);
        
        return left + right;
    } 

    vector<int> btWithKleaves(Node *ptr, int k) {
        
        vector<int> count;
        find(ptr, count, k);
        
        if(count.empty())
            count.push_back(-1);
            
        return count;
    }
};

int main() {
    /*
            1
          /   \
         2     3
        / \   /
       4   5 6
    */
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    int k = 2;

    Solution obj;
    vector<int> result = obj.btWithKleaves(root, k);

    cout << "Nodes with " << k << " leaf nodes in subtree: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}