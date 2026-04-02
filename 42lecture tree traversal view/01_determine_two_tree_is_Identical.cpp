#include<iostream>
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
    bool isIdentical(Node* r1, Node* r2) {
        if(!r1 && !r2)
            return true;
        
        if((!r1 && r2) || (r1 && !r2))
            return false;
        
        if(r1->data != r2->data)
            return false;
        
        return isIdentical(r1->left, r2->left) &&
               isIdentical(r1->right, r2->right);
    }
};

int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    Solution obj;
    bool result = obj.isIdentical(root1, root2);

    cout << "Are the two trees identical? " 
         << (result ? "Yes" : "No") << endl;

    return 0;
}