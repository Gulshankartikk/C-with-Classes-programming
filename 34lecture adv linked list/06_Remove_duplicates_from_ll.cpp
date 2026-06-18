#include <iostream>
#include <unordered_set>
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
    unordered_set<int> seen;
    seen.insert(head->data);
    Node* curr = head;
    while (curr->next != NULL) {
        if (seen.find(curr->next->data) != seen.end()) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            seen.insert(curr->next->data);
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
    // Example: 1 -> 2 -> 2 -> 4 -> 3 -> 3 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(3);

    cout << "Original list: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}