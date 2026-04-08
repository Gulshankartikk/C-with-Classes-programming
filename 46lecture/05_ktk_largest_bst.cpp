#include <iostream>
using namespace std;

// Definition of Node
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
        
        find(root->right, k, ans);
        
        k--;
        if(k == 0)
        {
            ans = root->data;
            return;
        }
        
        find(root->left, k, ans);
    }

    int kthLargest(Node *root, int k) {
        int ans = -1; // initialize to safe value
        find(root, k, ans);
        return ans;
    }
};

// Helper function to insert into BST
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

    // Creating BST
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for(int val : values) {
        root = insert(root, val);
    }

    int k = 3;

    Solution obj;
    int result = obj.kthLargest(root, k);

    cout << k << "rd largest element is: " << result << endl;

    return 0;
}