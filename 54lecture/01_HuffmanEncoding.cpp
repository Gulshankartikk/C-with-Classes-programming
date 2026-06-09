#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    class Node {
      public:
        int freq;
        Node *left, *right;

        Node(int count) {
            freq = count;
            left = right = NULL;
        }
    };

    class compare {
      public:
        bool operator()(Node *a, Node *b) {
            return a->freq > b->freq;
        }
    };

    void pre_order(Node *root, string s, vector<string>& huff) {
        if (!root)
            return;

        if (!root->left && !root->right) {
            huff.push_back(s);
            return;
        }

        pre_order(root->left, s + '0', huff);
        pre_order(root->right, s + '1', huff);
    }

    vector<string> huffmanCodes(string &s, vector<int> f) {

        int N = f.size();

        priority_queue<Node*, vector<Node*>, compare> minheap;

        for (int i = 0; i < N; i++) {
            Node *root = new Node(f[i]);
            minheap.push(root);
        }

        Node *first, *second;

        while (minheap.size() > 1) {

            first = minheap.top();
            minheap.pop();

            second = minheap.top();
            minheap.pop();

            Node *root = new Node(first->freq + second->freq);

            root->left = first;
            root->right = second;

            minheap.push(root);
        }

        Node *root = minheap.top();

        vector<string> huff;

        pre_order(root, "", huff);

        return huff;
    }
};

int main() {
    string s = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};

    Solution obj;

    vector<string> ans = obj.huffmanCodes(s, f);

    for (string code : ans) {
        cout << code << " ";
    }

    cout << endl;

    return 0;
}