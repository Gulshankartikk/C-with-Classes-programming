#include<iostream>
using namespace std;

// Define Node structure
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to calculate sum of last n nodes
int sumOfLastN_Nodes(Node* head, int n) {
    Node* fast = head;
    Node* slow = head;

    // Move fast n steps ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // Move both pointers
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // Sum last n nodes
    int sum = 0;
    while (slow != NULL) {
        sum += slow->data;
        slow = slow->next;
    }

    return sum;
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int n = 2;

    cout << "Sum: " << sumOfLastN_Nodes(head, n) << endl;

    return 0;
}