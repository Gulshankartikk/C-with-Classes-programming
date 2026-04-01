#include <iostream>
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

// Class Solution
class Solution {
public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return 1;

        return countLeaves(root->left) + countLeaves(root->right);
    }
};

int main() {
    /*
            Example Tree:
                1
               / \
              2   3
             / \   \
            4   5   6

        Leaf nodes: 4, 5, 6 → count = 3
    */

    // Creating the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Solution object
    Solution obj;

    // Output result
    cout << "Number of leaf nodes: " << obj.countLeaves(root) << endl;

    return 0;
}