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

Node* topNode = nullptr;
int cnt = 0;

bool isEmpty() {
    return topNode == nullptr;
}

void push(int x) {
    Node* temp = new Node(x);
    temp->next = topNode;
    topNode = temp;
    cnt++;
}

void pop() {
    if (isEmpty()) return;

    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
    cnt--;
}

int peek() {
    if (isEmpty()) return -1;
    return topNode->data;
}

int size() {
    return cnt;
}

int main() {
    push(5);
    push(3);
    push(4);

    cout << "Top: " << peek() << endl;     // 4

    pop();

    cout << "Size: " << size() << endl;    // 2
    cout << "Is Empty: " << isEmpty() << endl; // 0 (false)

    return 0;
}