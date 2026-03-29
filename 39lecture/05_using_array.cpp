#include <iostream>
using namespace std;

class myQueue {
    int *arr;
    int front, rear, size, count;

public:
    myQueue(int n) {
        size = n;
        arr = new int[n];
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = x;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        front = (front + 1) % size;
        count--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};

int main() {
    myQueue q(3);

    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(4);

    cout << "Front: " << q.getFront() << endl; // 5
    cout << "Rear: " << q.getRear() << endl;   // 4

    q.dequeue();

    cout << "Front after dequeue: " << q.getFront() << endl; // 3

    cout << "Is Empty: " << q.isEmpty() << endl; // 0 (false)
    cout << "Is Full: " << q.isFull() << endl;   // 0 (false)

    q.enqueue(10); // should reuse space (circular)

    cout << "Rear after enqueue: " << q.getRear() << endl; // 10

    return 0;
}