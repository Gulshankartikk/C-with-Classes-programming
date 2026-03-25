#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(1);
    s.push(24);
    s.push(345);
    s.pop();


    cout << s.empty();
    return 0;
}