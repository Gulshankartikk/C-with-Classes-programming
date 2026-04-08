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
  
    int find(vector<int> &inorder, int num, int start, int end)
    {
        for(int i = start; i <= end; i++)
        {
            if(inorder[i] == num)
                return i;
        }
        return -1;
    }
  
    Node *Tree(vector<int> &inorder, vector<int> &postorder, int start, int end, int &index)
    {
        if(start > end)
            return NULL;

        Node *root = new Node(postorder[index]);

        int i = find(inorder, postorder[index], start, end);

        index--;

        root->right = Tree(inorder, postorder, i + 1, end, index);
        root->left  = Tree(inorder, postorder, start, i - 1, index);

        return root;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int index = postorder.size() - 1;
        return Tree(inorder, postorder, 0, inorder.size() - 1, index);
    }
};

// Helper: Print inorder to verify tree
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    vector<int> inorder   = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1};

    Solution obj;
    Node* root = obj.buildTree(inorder, postorder);

    cout << "Inorder of constructed tree: ";
    printInorder(root);
    
    return 0;
}