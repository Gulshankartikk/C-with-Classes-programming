#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; 
};

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *head = new Node;
    head->data = arr[0];
    head->next = NULL;   // ✅ initialize

    Node *temp = head;

    for (int i = 1; i < n; i++)
    {
        temp->next = new Node;
        temp = temp->next;
        temp->data = arr[i];
        temp->next = NULL;   // ✅ important
    }

    print(head);
    return 0;
}