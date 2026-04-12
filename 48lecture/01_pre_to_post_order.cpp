#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    TreeNode* find(int pre[], int min, int max, int &index, int size) {
        if (index >= size || pre[index] < min || pre[index] > max)
            return NULL;

        TreeNode* root = new TreeNode(pre[index]);
        index++;

        root->left = find(pre, min, root->val, index, size);
        root->right = find(pre, root->val, max, index, size);

        return root;
    }

    TreeNode* buildBST(int pre[], int size) {
        int index = 0;
        return find(pre, INT_MIN, INT_MAX, index, size);
    }
};

// ✅ Inorder traversal (to verify BST)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution obj;

    int preorder[] = {8, 5, 1, 7, 10, 12};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    TreeNode* root = obj.buildBST(preorder, size);

    cout << "Inorder Traversal (should be sorted): ";
    inorder(root);

    return 0;
}