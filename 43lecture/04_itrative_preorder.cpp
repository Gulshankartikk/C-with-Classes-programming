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

// Function to build tree from level order input
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string s; iss >> s;)
        ip.push_back(s);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < ip.size()) {
        Node* curr = q.front();
        q.pop();

        // Left child
        if (ip[i] != "N") {
            curr->left = new Node(stoi(ip[i]));
            q.push(curr->left);
        }
        i++;
        if (i >= ip.size()) break;

        // Right child
        if (ip[i] != "N") {
            curr->right = new Node(stoi(ip[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        
        if (!root) return ans;

        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* temp = s.top();
            s.pop();

            ans.push_back(temp->data);

            if (temp->right)
                s.push(temp->right);
            if (temp->left)
                s.push(temp->left);
        }
        return ans;
    }
};

int main() {
    string input;
    getline(cin, input);  // Example: 1 2 3 N N 4 5

    Node* root = buildTree(input);

    Solution obj;
    vector<int> result = obj.preOrder(root);

    for (int x : result)
        cout << x << " ";
    
    cout << endl;

    return 0;
}