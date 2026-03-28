#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node *insertInMiddle(Node *head, int x) {
        
        // If list is empty
        if (head == NULL) {
            return new Node(x);
        }

        Node* slow = head;
        Node* fast = head;

        // Find middle
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Insert after middle
        Node* newNode = new Node(x);
        newNode->next = slow->next;
        slow->next = newNode;

        return head;
    }
};

// Function to insert at end
Node* insertAtEnd(Node* head, int val) {
    if (head == NULL) return new Node(val);

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}

// Function to print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, val, x;

    // Input number of elements
    cin >> n;

    // Input linked list
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertAtEnd(head, val);
    }

    // Value to insert
    cin >> x;

    Solution obj;
    head = obj.insertInMiddle(head, x);

    // Output result
    printList(head);

    return 0;
}