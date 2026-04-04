#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;

        queue<TreeNode *> q;
        stack<TreeNode *> s;
        q.push(root);

        bool dir = 0;
        TreeNode *temp;

        while(!q.empty())
        {
            int size = q.size();  
            vector<int> level;

            if(dir == 0)
            {
                while(size--)   
                {
                    temp = q.front();
                    q.pop();
                    
                    if(temp->left)
                        s.push(temp->left);
                    if(temp->right)
                        s.push(temp->right);

                    level.push_back(temp->val);
                }
                dir = 1;
            }
            else
            {
                while(size--)   
                {
                    temp = q.front();
                    q.pop();

                    if(temp->right)
                        s.push(temp->right);
                    if(temp->left)
                        s.push(temp->left);

                    level.push_back(temp->val);
                }
                dir = 0;
            }

            ans.push_back(level);

            while(!s.empty())
            {
                q.push(s.top());
                s.pop();
            }
        }

        return ans;
    }
};

int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<vector<int>> result = obj.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:\n";
    for(auto level : result) {
        for(int x : level)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}