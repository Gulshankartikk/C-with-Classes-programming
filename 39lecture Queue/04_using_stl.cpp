#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<"front element is "<<q.front()<<endl;
    cout<<"back element is "<<q.back()<<endl;
    return 0;
}
