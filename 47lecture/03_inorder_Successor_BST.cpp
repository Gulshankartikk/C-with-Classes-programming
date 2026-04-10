#include <bits/stdc++.h>
using namespace std;

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
    void find(Node *root, Node *x, Node *&ans, bool &found)
    {
        if(!root || ans) return;

        find(root->left, x, ans, found);

        if(found && ans == NULL) {
            ans = root;
            return;
        }

        if(root == x) {
            found = true;
        }

        find(root->right, x, ans, found);
    }

    int inOrderSuccessor(Node *root, Node *x) {
        Node *ans = NULL;
        bool found = false;

        find(root, x, ans, found);

        if(ans == NULL)
            return -1;

        return ans->data;   // ✅ THIS FIXES YOUR ISSUE
    }
};
int main()
{
    /*
        Constructing this tree:
                4
               / \
              2   5
             / \
            1   3
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution obj;

    int successor = obj.inOrderSuccessor(root, root->left); // Finding successor of node with value 2

    if(successor != -1) {
        cout << "In-order Successor of " << root->left->data << " is: " << successor << endl;
    } else {
        cout << "In-order Successor does not exist." << endl;
    }
}