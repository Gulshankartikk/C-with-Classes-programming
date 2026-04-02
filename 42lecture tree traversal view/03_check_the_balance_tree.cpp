#include<iostream>
using namespace std;

class TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;

   TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution {
public:
     int height(TreeNode *root,bool &ans)
    {
        if(!root)
        return 0;
        int left =height(root->left,ans);
        int right =height(root->right,ans);
        
        if(abs(left-right)>1)
        ans =0;
        
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        bool ans =1;
        height(root,ans);
        return ans; 
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;
    bool result = obj.isBalanced(root);

    cout << "Is the binary tree balanced? " 
         << (result ? "Yes" : "No") << endl;

    return 0;
}