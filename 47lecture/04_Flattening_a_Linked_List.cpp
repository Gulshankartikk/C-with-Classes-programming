#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;
    
    Node(int val) {
        data = val;
        next = NULL;
        bottom = NULL;
    }
};
class Solution {
  public:
  
    // Merge two sorted bottom-linked lists
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result;

        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        result->next = NULL; // important
        return result;
    }

    Node *flatten(Node *root) {
        // base case
        if (!root || !root->next)
            return root;

        // flatten the rest of the list
        root->next = flatten(root->next);

        // merge current list with flattened next
        root = merge(root, root->next);

        return root;
    }
};
int main()
{
    /*
        Constructing this linked list:
        5 -> 10 -> 19 -> 28
        |     |     |     |
        V     V     V     V
        7     20    22    35
              |           |
              V           V
              40          40
    */

    Node* head = new Node(5);
    head->bottom = new Node(7);
    
    head->next = new Node(10);
    head->next->bottom = new Node(20);
    head->next->bottom->bottom = new Node(40);
    
    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    
    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);

    Solution obj;
    Node* flattenedHead = obj.flatten(head);

    // Print the flattened list
    cout << "Flattened list: ";
    while (flattenedHead) {
        cout << flattenedHead->data << " ";
        flattenedHead = flattenedHead->bottom;
    }
}