#include<iostream>
using namespace std;

class queue
{
    int front;
    int rear;
    int* arr;
    int size;

public:
    queue(int size)
    {
        front = rear = 0;
        this->size = size;   // FIX: store size
        arr = new int[size];
    }

    void push(int data)
    {
        if (rear == size)
        {
            cout << "queue is full\n";
            return;
        }
        arr[rear] = data;
        rear++;
    }

    void pop()
    {
        if (front == rear)
        {
            cout << "queue is empty\n";
            return;
        }
        front++;
    }

    bool empty()
    {
        return front == rear;
    }
};

// ✅ main() MUST be outside
int main()
{
    queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.pop();
    q.push(6); // will still say full (linear queue limitation)

    return 0;
}