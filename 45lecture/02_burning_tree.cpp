#include <bits/stdc++.h>
using namespace std;

// Node definition (GFG style)
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
    int Burn(Node *root, int target,int&timer)
    {
        if(!root)
        return 0;
        
        if(root->data==target)
        return -1;

        int left = Burn(root->left,target,timer);
        int right = Burn(root->right,target,timer);
        
        if(left < 0)
        {
            timer = max(timer, abs(left) + right);
            return left - 1;
        }

        if(right < 0)
        {
            timer = max(timer, abs(right) + left);
            return right - 1;
        }

        return max(left, right) + 1;
    }
    
    void find(Node *root,int target,Node *&temp)
    {
        if(!root)
        return;

        if(root->data == target)
        {
            temp = root;
            return;
        }

        find(root->left,target,temp);
        find(root->right,target,temp);
    }

    int Height(Node *root)
    {
        if(!root)
        return 0;
         
        return 1 + max(Height(root->left), Height(root->right));
    }

    int minTime(Node* root, int target) {
        int timer = 0;
        Burn(root,target,timer);

        Node *temp = NULL;
        find(root,target,temp);

        int num = Height(temp) - 1;

        return max(timer, num);
    }
};

int main() {
    /*
        Example Tree:
               1
             /   \
            2     3
           / \     \
          4   5     6
             /
            7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->right->right = new Node(6);

    int target = 5;

    Solution obj;
    cout << "Minimum time to burn tree: "
         << obj.minTime(root, target);

    return 0;
}