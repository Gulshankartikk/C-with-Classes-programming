#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;

            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root;

public:

    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        Node* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->child[index] == nullptr) {
                curr->child[index] = new Node();
            }

            curr = curr->child[index];
        }

        curr->isEnd = true;
    }

    bool search(string &word) {
        Node* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->child[index] == nullptr) {
                return false;
            }

            curr = curr->child[index];
        }

        return curr->isEnd;
    }

    bool isPrefix(string &word) {
        Node* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->child[index] == nullptr) {
                return false;
            }

            curr = curr->child[index];
        }

        return true;
    }
};

int main() {

    Trie trie;

    // Insert words
    string word1 = "abcd";
    string word2 = "abc";
    string word3 = "bcd";

    trie.insert(word1);
    trie.insert(word2);
    trie.insert(word3);

    // Search
    string s1 = "bc";
    string s2 = "abc";

    cout << boolalpha;

    cout << "Search bc: " << trie.search(s1) << endl;
    cout << "Search abc: " << trie.search(s2) << endl;

    // Prefix
    string p1 = "bc";
    string p2 = "xyz";

    cout << "Prefix bc: " << trie.isPrefix(p1) << endl;
    cout << "Prefix xyz: " << trie.isPrefix(p2) << endl;

    return 0;
}