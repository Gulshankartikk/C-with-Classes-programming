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

    int sumTree(Node *root,bool &ans)
    {
        if(!root)
            return 0;

        //identify leaf node
        if(!root->left && !root->right)
            return root->data;

        //left sum
        int left = sumTree(root->left, ans);

        //right sum
        int right = sumTree(root->right, ans);

        if(left + right != root->data)
            ans = 0;

        return left + right + root->data;  // ✅ missing return added
    }

    bool isSumTree(Node* root) {
        bool ans = 1;
        sumTree(root, ans);
        return ans;
    }
};

int main()
{
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    Solution obj;
    bool result = obj.isSumTree(root);

    cout << "Is the binary tree a Sum Tree? " << (result ? "Yes" : "No") << endl;

    return 0;
}