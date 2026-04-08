#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;
    Node(int x)
    {
        data=x;
        left=right=NULL;
    };
};
Node * BST(Node *root, int value)
{
    if(!root)
        return new Node(value);

    if(root->data > value)
        root->left = BST(root->left, value);
    else
        root->right = BST(root->right, value);

    return root;
}
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}
Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor
        Node* temp = findMin(root->right);
        root->data = temp->data; // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}
void inorder(Node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main()
{
    int arr[10]={10,13,4,8,11,19,2,7,18,23};
    Node *root =NULL;
    
    for(int i=0;i<10;i++)
        root = BST(root, arr[i]);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    int keyToDelete = 10;
    root = deleteNode(root, keyToDelete);

    cout << "Inorder after deleting " << keyToDelete << ": ";
    inorder(root);
    cout << endl;

    return 0;
}