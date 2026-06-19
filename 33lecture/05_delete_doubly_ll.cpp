#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

Node* deleteNode(Node* head, int x) {
    if (head == NULL) return head;

    // Delete first node
    if (x == 1) {
        head = head->next;
        if (head) head->prev = NULL;
        return head;
    }

    Node* curr = head;

    for (int i = 1; i < x; i++) {
        curr = curr->next;
    }

    if (curr->prev)
        curr->prev->next = curr->next;

    if (curr->next)
        curr->next->prev = curr->prev;

    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    cout << "Original DLL: ";
    printList(head);

    int x = 3; // Delete node at position 3
    head = deleteNode(head, x);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}