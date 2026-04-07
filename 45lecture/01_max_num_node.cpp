#include <bits/stdc++.h>
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
  
    int maxSum(Node *root, int &sum)
    {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return root->data;

        int left = maxSum(root->left, sum);
        int right = maxSum(root->right, sum);

        if (root->left && root->right)
        {
            sum = max(sum, root->data + left + right);
            return root->data + max(left, right);
        }

        if (root->left)
            return root->data + left;

        return root->data + right;
    }

    int maxPathSum(Node *root)
    {
        int sum = INT_MIN;
        int val = maxSum(root, sum);

        if (root->left && root->right)
            return sum;

        return max(sum, val);
    }
};

int main() {
    /*
        Example Tree:
              10
             /  \
            2    10
           / \     \
          20  1     -25
                      /  \
                     3    4
    */

    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    Solution obj;
    cout << "Maximum Path Sum (Leaf to Leaf): "
         << obj.maxPathSum(root);

    return 0;
}