#include<iostream>
#include<stack>
using namespace std;

void deleteMid(stack<int>& s) {
    stack<int> temp;
    int size = s.size();
    int count = size / 2;
    
    while (count-- && !s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    
    if (!s.empty())
        s.pop();
    
    while (temp.size())
    {
        s.push(temp.top());
        temp.pop();
    }
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    deleteMid(s);

    // Print stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}