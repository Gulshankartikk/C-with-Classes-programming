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
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
  
  void InorderTraversal(Node *root, vector<int>& ans)
  {
      if(!root)
          return;
          
      InorderTraversal(root->left, ans);
      ans.push_back(root->data);
      InorderTraversal(root->right, ans);
  }

  vector<int> inOrder(Node* root) {
      vector<int> ans;
      InorderTraversal(root, ans);
      return ans;
  }
};

int main()
{
    // Creating a sample tree:
    //        1
    //       / \
    //      2   3

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Solution obj;
    vector<int> result = obj.inOrder(root);

    cout << "Inorder Traversal: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}