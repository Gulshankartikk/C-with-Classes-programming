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
    int find(TreeNode *root,int & ans)
    {
        if(!root)
        return 0;
        
        int left = find(root->left,ans);
        int right = find(root->right,ans);
        
        ans = max(ans, left + right);
        
        return 1 + max(left,right);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
         int ans =0;
        find(root,ans);
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
    int result = obj.diameterOfBinaryTree(root);

    cout << "Diameter of the binary tree: " << result << endl;

    return 0;
}