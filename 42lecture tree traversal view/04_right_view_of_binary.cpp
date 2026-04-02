#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    vector<int> rightView(Node *root) {
        //  code here
         vector<int>ans;
        queue<Node *>q;
        int size;
        q.push(root);
        
        while(!q.empty())
        {
            ans.push_back(q.front()->data);
            size =q.size();
            while(size--)
            {
                Node *temp =q.front();
                q.pop();
                if(temp->right)
                q.push(temp->right);
                if(temp->left)
                q.push(temp->left);
            }
        }
        return ans;
    }
};
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;
    vector<int> result = obj.rightView(root);

    cout << "Right View of the binary tree: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}