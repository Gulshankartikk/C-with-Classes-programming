#include <iostream>
#include <stack>
using namespace std;

stack<int> minStack;

// Push
void push(stack<int>& s, int x) {
    s.push(x);

    if (minStack.empty() || x <= minStack.top()) {
        minStack.push(x);
    }
}

// Pop
int pop(stack<int>& s) {
    if (s.empty()) return -1;

    int val = s.top();
    s.pop();

    if (!minStack.empty() && val == minStack.top()) {
        minStack.pop();
    }

    return val;
}

// Check empty
bool isEmpty(stack<int>& s) {
    return s.empty();
}

// Check full
bool isFull(stack<int>& s, int size) {
    return s.size() == size;
}

// Get minimum
int getMin(stack<int>& s) {
    if (minStack.empty()) return -1;
    return minStack.top();
}

int main() {
    stack<int> s;
    int capacity = 10; // example capacity

    // Pushing elements
    push(s, 18);
    push(s, 19);
    push(s, 29);
    push(s, 15);
    push(s, 16);

    cout << "Current Min: " << getMin(s) << endl;  // Expected: 15

    cout << "Is Empty: " << (isEmpty(s) ? "Yes" : "No") << endl;

    cout << "Is Full: " << (isFull(s, capacity) ? "Yes" : "No") << endl;

    cout << "Popped: " << pop(s) << endl;  // removes 16

    cout << "Current Min after pop: " << getMin(s) << endl;  // Expected: 15

    // Pop until empty
    while (!isEmpty(s)) {
        cout << "Popped: " << pop(s) << endl;
    }

    cout << "Is Empty after clearing: " << (isEmpty(s) ? "Yes" : "No") << endl;

    return 0;
}