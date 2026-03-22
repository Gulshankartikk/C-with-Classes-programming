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

// Function to remove loop (your logic, fixed types)
void removeLoop(ListNode* head) {
    if(head == NULL)
        return;

    if(head == head->next) {
        head->next = NULL;
        return;
    }

    ListNode* slow = head->next;
    ListNode* fast = head->next->next;

    while(fast && fast->next && fast != slow) {
        fast = fast->next->next;
        slow = slow->next;
    }

    if(!fast || !fast->next)
        return;

    fast = head;

    if(fast == slow) {
        while(slow->next != fast)
            slow = slow->next;

        slow->next = NULL;
        return;
    }

    while(fast->next != slow->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;
}

// Safe print (won’t infinite loop)
void printList(ListNode* head) {
    ListNode* temp = head;
    int count = 0;

    while(temp && count < 20) { // limit to avoid infinite loop
        cout << temp->val << " -> ";
        temp = temp->next;
        count++;
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

    // Create loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    cout << "Loop created (printing limited nodes):\n";
    printList(head);

    // Remove loop
    removeLoop(head);

    cout << "\nAfter removing loop:\n";
    printList(head);

    return 0;
}