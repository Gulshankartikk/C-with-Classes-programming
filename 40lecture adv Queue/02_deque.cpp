#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    cout << "Front element: " << dq.front() << endl;
    cout << "Rear element: " << dq.back() << endl;

    dq.push_front(0);
    cout << "Front element after push_front: " << dq.front() << endl;

    dq.pop_back();
    cout << "Rear element after pop_back: " << dq.back() << endl;

    return 0;
}