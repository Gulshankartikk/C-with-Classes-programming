#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{/*
    //max heap
    priority_queue<int>p;
    //1:push insert
    p.push(4);
    p.push(8);
    p.push(2);
    p.push(7);
    p.pop();
    cout<<p.top()<<" ";
    cout<<p.empty();
    //2:pop delete
    //3:find value of max element top element
    //4:size of heap
    //5:is heap empty
    // min heap
    return 0;*/


    //min heap
    priority_queue<int,vector<int>, greater<int> >p;
    p.push(4);
    p.push(8);
    p.push(2);
    p.push(7);
    p.pop();
    cout<<p.top();
    return 0;
}