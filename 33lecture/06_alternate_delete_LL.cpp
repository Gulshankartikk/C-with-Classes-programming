#include <iostream>
using namespace std;

// Structure of Linked List Node
struct Node {
    int data;
    Node* next;
    
    // Constructor to easily create a new node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to delete alternate nodes
void deleteAlt(Node* head) {
    if (head == nullptr)
        return;

    Node* prev = head;
    Node* node = head->next;

    while (prev != nullptr && node != nullptr) {
        // Skip the alternate node
        prev->next = node->next;

        // Free memory of the deleted node
        delete node;

        // Move prev forward
        prev = prev->next;

        // Update node to be the new alternate node
        if (prev != nullptr) {
            node = prev->next;
        }
    }
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    // Delete alternate nodes
    deleteAlt(head);

    cout << "After Deleting Alternate Nodes: ";
    printList(head);

    return 0;
}
