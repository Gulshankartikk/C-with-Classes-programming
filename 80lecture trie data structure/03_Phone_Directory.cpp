#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    class TrieNode {
    public:
        bool isEndofWord;
        TrieNode* child[26];

        TrieNode() {
            isEndofWord = false;

            for (int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };

    class Trie {
        TrieNode* root;

    public:

        Trie() {
            root = new TrieNode();
        }

        void insert(string word) {
            TrieNode* node = root;

            for (char c : word) {
                int index = c - 'a';

                if (node->child[index] == NULL) {
                    node->child[index] = new TrieNode();
                }

                node = node->child[index];
            }

            node->isEndofWord = true;
        }

        void findContact(string prefix, TrieNode* node,
                         vector<string>& contact) {

            if (node->isEndofWord) {
                contact.push_back(prefix);
            }

            for (char c = 'a'; c <= 'z'; c++) {
                int index = c - 'a';

                if (node->child[index] != NULL) {
                    findContact(prefix + c,
                                node->child[index],
                                contact);
                }
            }
        }

        vector<string> searchContact(string prefix) {

            TrieNode* node = root;

            for (char c : prefix) {
                int index = c - 'a';

                if (node->child[index] == NULL) {
                    return {"0"};
                }

                node = node->child[index];
            }

            vector<string> contact;

            findContact(prefix, node, contact);

            return contact;
        }
    };

    vector<vector<string>> displayContacts(vector<string>& contact,
                                           string& s) {

        Trie tree;

        int n = contact.size();

        for (int i = 0; i < n; i++) {
            tree.insert(contact[i]);
        }

        vector<vector<string>> result;

        string prefix = "";

        for (int i = 0; i < s.length(); i++) {

            prefix += s[i];

            vector<string> contacts =
                tree.searchContact(prefix);

            result.push_back(contacts);
        }

        return result;
    }
};

int main() {

    Solution obj;

    vector<string> contact = {
        "alice",
        "ali",
        "alex",
        "bob",
        "alisha"
    };

    string s = "ali";

    vector<vector<string>> result =
        obj.displayContacts(contact, s);

    // Print result
    for (int i = 0; i < result.size(); i++) {

        cout << "Prefix " << s.substr(0, i + 1) << ": ";

        for (string name : result[i]) {
            cout << name << " ";
        }

        cout << endl;
    }

    return 0;
}