#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

};

int main() 
{
    Node *first = new Node;
    first->data=10;
    return 0;
}