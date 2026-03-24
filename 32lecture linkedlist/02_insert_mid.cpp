#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

class Solution {
public:
    Node *insertInMiddle(Node *head, int x) {
        
        if (head == NULL) {
            return new Node(x);
        }

        Node *temp1 = head;
        int count = 0;

        while (temp1 != NULL) {
            count++;
            temp1 = temp1->next;
        }

        int mid = count / 2;
        temp1 = head;

        for (int i = 0; i < mid - 1; i++) {   // ✅ FIXED
            temp1 = temp1->next;
        }

        Node *temp = new Node(x);
        
        temp->next = temp1->next;
        temp1->next = temp;

        return head;               
    }
};

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    int x;
    cin >> x;

    Solution obj;
    head = obj.insertInMiddle(head, x);

    print(head);

    return 0;
}