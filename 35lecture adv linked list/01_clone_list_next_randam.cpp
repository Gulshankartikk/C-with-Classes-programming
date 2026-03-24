#include<iostream>
using namespace std;

// Node with random pointer
class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* cloneLinkedList(Node* head) {

        if (!head) return NULL;

        Node* clone = head;
        Node* temp;

        // Step 1: Insert cloned nodes
        while (clone) {
            temp = new Node(clone->data);
            temp->next = clone->next;
            clone->next = temp;
            clone = temp->next;
        }

        // Step 2: Copy random pointers
        clone = head;
        while (clone) {
            if (clone->random)
                clone->next->random = clone->random->next;

            clone = clone->next->next;
        }

        // Step 3: Separate lists
        Node* ans = head->next;
        clone = head;
        temp = ans;

        while (clone) {
            clone->next = temp->next;

            if (temp->next)
                temp->next = temp->next->next;

            clone = clone->next;
            temp = temp->next;
        }

        return ans;
    }
};

int main() {
    // Create sample list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Set random pointers
    head->random = head->next->next;   // 1 -> 3
    head->next->random = head;         // 2 -> 1
    head->next->next->random = head->next; // 3 -> 2

    Solution obj;
    Node* cloned = obj.cloneLinkedList(head);

    // Print cloned list (data + random)
    while (cloned) {
        cout << "Data: " << cloned->data;

        if (cloned->random)
            cout << ", Random: " << cloned->random->data;
        else
            cout << ", Random: NULL";

        cout << endl;
        cloned = cloned->next;
    }

    return 0;
}