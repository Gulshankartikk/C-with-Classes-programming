#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Your reverse function (unchanged logic)
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* temp;
    
    while(head)
    {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    
    return prev;
}

// Function to print linked list
void printList(ListNode* head) {
    while(head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Creating list: 1 -> 2 -> 3 -> 4 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original List:\n";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List:\n";
    printList(head);

    return 0;
}