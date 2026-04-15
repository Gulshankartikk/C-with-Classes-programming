#include <bits/stdc++.h>
using namespace std;

// Node structure
struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    TreeNode *minValue (TreeNode *root)
    {
        TreeNode *current = root;
        while(current && current->left)
            current = current->left;
        return current;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        
        if(root->data == key)   // ✅ fixed
        {
            if(!root->right && !root->left)
            {
                delete root;
                return NULL;
            }
            else if(root->left && !root->right)
            {
                TreeNode * temp = root->left;
                delete root; 
                return temp;
            }
            else if(!root->left && root->right)
            {  
                TreeNode * temp = root->right;
                delete root; 
                return temp; 
            }
            else
            {
                TreeNode *temp = minValue(root->right);
                root->data = temp->data;   // ✅ fixed
                root->right = deleteNode(root->right, temp->data);  // ✅ fixed
            }
        }
        else if(key < root->data)   // ✅ fixed
        {
            root->left = deleteNode(root->left, key);
        }
        else   
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

// 🔹 Inorder traversal (for checking result)
void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    // Creating BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution obj;

    cout << "Before deletion: ";
    inorder(root);
    cout << endl;

    // Delete node
    root = obj.deleteNode(root, 3);

    cout << "After deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}