#include<iostream>
using namespace std;

// Define Node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void deleteNode(Node* del_node) {
    // Safety check
    if (del_node == NULL || del_node->next == NULL) {
        return; // cannot delete last node
    }

    // Copy next node data
    del_node->data = del_node->next->data;

    // Store next node
    Node* temp = del_node->next;

    // Skip next node
    del_node->next = del_node->next->next;

    // Delete next node
    delete temp;
}
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Delete node with value 3
    deleteNode(head->next->next);

    // Print updated list
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}