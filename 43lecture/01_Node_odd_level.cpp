#include<iostream>
#include<vector>

using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void PreOrder(Node *root, vector<int> &ans, int level)
    {
        if (!root)
            return;

        if (level % 2 == 1)
            ans.push_back(root->data);

        PreOrder(root->left, ans, level + 1);
        PreOrder(root->right, ans, level + 1);
    }

    vector<int> nodesAtOddLevels(Node *root) {
        vector<int> ans;
        int level = 1;
        PreOrder(root, ans, level);
        return ans;
    }
};

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;
    vector<int> result = obj.nodesAtOddLevels(root);

    cout << "Nodes at odd levels of the binary tree: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}