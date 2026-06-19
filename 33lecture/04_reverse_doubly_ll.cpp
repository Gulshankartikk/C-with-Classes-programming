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

Node* reverseDLL(Node* head) {
    Node* curr = head;
    Node* temp = NULL;

    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp)
        head = temp->prev;

    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(4);
    head->next->prev = head;

    head->next->next = new Node(5);
    head->next->next->prev = head->next;

    cout << "Original DLL: ";
    printList(head);

    head = reverseDLL(head);

    cout << "\nReversed DLL: ";
    printList(head);

    return 0;
}