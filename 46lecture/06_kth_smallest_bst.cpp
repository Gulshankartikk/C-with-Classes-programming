#include <iostream>
using namespace std;

// Node definition
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
    void find(Node *root, int &k, int &ans)
    {
        if(!root)
            return;
        
        find(root->left, k, ans);  // LEFT first
        
        k--;
        if(k == 0)
        {
            ans = root->data;
            return;
        }
        
        find(root->right, k, ans); // RIGHT after
    }

    int kthSmallest(Node *root, int k) {
        int ans = -1;
        find(root, k, ans);
        return ans;
    }
};

// Insert into BST
Node* insert(Node* root, int val) {
    if(!root) return new Node(val);
    
    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    
    return root;
}

int main() {
    Node* root = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for(int val : values) {
        root = insert(root, val);
    }

    int k = 3;

    Solution obj;
    cout << k << "rd smallest element is: "
         << obj.kthSmallest(root, k) << endl;

    return 0;
}