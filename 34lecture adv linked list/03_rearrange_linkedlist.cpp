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

ListNode* rearrangeEvenOdd(ListNode *head) {
    if (!head || !head->next)
        return head;

    ListNode *first = head;
    ListNode *second = head->next;
    ListNode *temp = second;

    while (second && second->next) {
        first->next = second->next;
        first = first->next;

        second->next = first->next;
        second = second->next;
    }

    first->next = temp;

    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List:\n";
    printList(head);

    head = rearrangeEvenOdd(head);

    cout << "After rearranging:\n";
    printList(head);

    return 0;
}