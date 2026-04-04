#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }   // ✅ fixed
};      // ✅ fixed

class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        vector<int> ans;
        if(!root)
            return ans;

        queue<Node *> q;
        stack<Node *> s;
        q.push(root);

        bool dir = 0; // 0: right->left, 1: left->right
        Node *temp;

        while(!q.empty())
        {
            int size = q.size();

            if(dir == 0)
            {
                while(size--)
                {
                    temp = q.front();
                    q.pop();

                    if(temp->right)
                        s.push(temp->right);
                    if(temp->left)
                        s.push(temp->left);

                    ans.push_back(temp->data);
                }
                dir = 1;
            }
            else
            {
                while(size--)
                {
                    temp = q.front();
                    q.pop();

                    if(temp->left)
                        s.push(temp->left);
                    if(temp->right)
                        s.push(temp->right);

                    ans.push_back(temp->data);
                }
                dir = 0;
            }

            while(!s.empty())
            {
                q.push(s.top());
                s.pop();
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    vector<int> result = obj.findSpiral(root);

    cout << "Spiral order traversal of the binary tree: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}