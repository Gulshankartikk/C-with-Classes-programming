#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
  
    void find(Node *root, Node *&prev, Node *&first, Node *&second) {
        if (!root) return;
        
        // Left
        find(root->left, prev, first, second);
        
        // Process
        if (prev && prev->data > root->data) {
            if (!first) {
                first = prev;
            }
            second = root;
        }
        
        prev = root;
        
        // Right
        find(root->right, prev, first, second);
    }

    Node* correctBST(Node *root) {
        Node *prev = NULL, *first = NULL, *second = NULL;
        find(root, prev, first, second);

        // Swap values
        if (first && second) {
            int temp = first->data;
            first->data = second->data;
            second->data = temp;
        }

        return root;
    }
};

// Helper: Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    /*
        Constructing a BST:
              6
             / \
            3   8
           / \   \
          1   4   10

        Now swap two nodes manually (corrupt BST)
        Swap 3 and 10
    */



    kjdfjkds

    Node* root = new Node(6);
    root->left = new Node(10);   // wrong
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(3); // wrong

    cout << "Inorder before fixing: ";
    inorder(root);
    cout << endl;

    Solution obj;
    root = obj.correctBST(root);

    cout << "Inorder after fixing: ";
    inorder(root);
    cout << endl;

    return 0;
}