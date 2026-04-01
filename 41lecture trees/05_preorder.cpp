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
  
  void preorderTraversal(Node *root, vector<int>& ans)
  {
      if(!root)
          return;
       ans.push_back(root->data);   
      preorderTraversal(root->left, ans);
      
      preorderTraversal(root->right, ans);
  }

  vector<int> preOrder(Node* root) {
      vector<int> ans;
      preorderTraversal(root, ans);
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
    vector<int> result = obj.preOrder(root);

    cout << "preorder Traversal: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}