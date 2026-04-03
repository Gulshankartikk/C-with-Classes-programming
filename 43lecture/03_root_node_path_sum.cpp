#include<iostream>
#include<vector>

using namespace std;
class TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution {
public:
    long long findSum(TreeNode *root, long long &sum, long long num)
    {
        if(!root)
            return 0;
        
        num = num * 10 + root->data;

        // leaf node
        if(!root->left && !root->right)
        {
            sum += num;
            return root->data;
        }
        
        long long left = findSum(root->left, sum, num);
        long long right = findSum(root->right, sum, num);

        return left + right + root->data;
    }

    int sumNumbers(TreeNode* root) {
        long long sum = 0;
        long long num = 0;
        
        findSum(root, sum, num);
        return sum;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution obj;
    int result = obj.sumNumbers(root);

    cout << "Sum of root-to-leaf numbers: " << result << endl;

    return 0;
}