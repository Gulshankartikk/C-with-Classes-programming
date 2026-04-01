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
  
  void postorderTraversal(Node *root, vector<int>& ans)
  {
      if(!root)
          return;
          
      postorderTraversal(root->left, ans);
      postorderTraversal(root->right, ans);
      ans.push_back(root->data);
  }

  vector<int> postOrder(Node* root) {   // ✅ fixed name
      vector<int> ans;
      postorderTraversal(root, ans);
      return ans;
  }
};

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Solution obj;
    vector<int> result = obj.postOrder(root); // ✅ matches function

    cout << "Postorder Traversal: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}