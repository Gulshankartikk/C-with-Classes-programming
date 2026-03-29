#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    Queue() {
        front = rear = NULL;
        count = 0;
    }

    void enqueue(int x) {
        Node* temp = new Node(x);

        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        count++;
    }

    void dequeue() {
        if (front == NULL) return;

        Node* temp = front;
        front = front->next;

        if (front == NULL) rear = NULL;

        delete temp;
        count--;
    }

    int getFront() {
        if (front == NULL) return -1;
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }

    int size() {
        return count;
    }
};

int main() {
    Queue q;

    int queries;
    cin >> queries;

    while (queries--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            q.enqueue(x);
        }
        else if (type == 2) {
            q.dequeue();
        }
        else if (type == 3) {
            cout << q.getFront() << " ";
        }
        else if (type == 4) {
            cout << (q.isEmpty() ? "true" : "false") << " ";
        }
        else if (type == 5) {
            cout << q.size() << " ";
        }
    }

    return 0;
}