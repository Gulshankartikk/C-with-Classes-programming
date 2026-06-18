#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* removeDuplicates(Node* head) {
    if (head == NULL) return head;

    Node* curr = head;
    while (curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Example 1: 2 -> 2 -> 4 -> 5
    Node* head1 = new Node(2);
    head1->next = new Node(2);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head1);
    head1 = removeDuplicates(head1);
    cout << "After removing duplicates: ";
    printList(head1);

    cout << endl;

    // Example 2: 2 -> 2 -> 2 -> 2 -> 2
    Node* head2 = new Node(2);
    head2->next = new Node(2);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(2);
    head2->next->next->next->next = new Node(2);

    cout << "Original list: ";
    printList(head2);
    head2 = removeDuplicates(head2);
    cout << "After removing duplicates: ";
    printList(head2);

    return 0;
}