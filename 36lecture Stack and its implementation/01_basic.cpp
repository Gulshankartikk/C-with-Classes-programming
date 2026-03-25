#include <iostream>
using namespace std;

class stack
{
    int top;
    int *arr;
    int size;

public:
    stack(int s)
    {
        arr = new int[s];
        top = -1;
        size = s;
    };

    // push element in stack
    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "stack overflow\n";
            return;
        }
        top++;
        arr[top] = data;
    }

    // pop element from the array
    void pop()
    {
        if (top == -1)
        {
            cout << "stack underflow\n";
            return;
        }
        top--;
        return;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "stack underflow";
            return -1;
        }
        return arr[top];
    }
};

int main()
{
    stack s(5);
    s.push(1);
    s.push(24);
    s.push(345);
    s.push(4);
    s.push(565);
    s.push(64); // stack overflow
    cout << s.peek() << endl;

    s.pop();
    s.pop();
    s.pop(); // stack underflow
    cout << s.peek() << endl;
}