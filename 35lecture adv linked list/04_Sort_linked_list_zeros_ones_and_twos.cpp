#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* segregate(Node* head) {
    int count[3] = {0, 0, 0};

    Node* temp = head;

    // Count 0s, 1s, and 2s
    while (temp != nullptr) {
        count[temp->data]++;
        temp = temp->next;
    }

    // Overwrite node values
    temp = head;
    int i = 0;

    while (temp != nullptr) {
        if (count[i] == 0) {
            i++;
        } else {
            temp->data = i;
            count[i]--;
            temp = temp->next;
        }
    }

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    if (n == 0)
        return 0;

    int x;
    cin >> x;
    Node* head = new Node(x);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }

    head = segregate(head);

    printList(head);

    return 0;
}