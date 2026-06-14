#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

int main() {
    int n;
    cin >> n;

    ListNode *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ListNode *newNode = new ListNode(x);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Find middle
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    ListNode *prev = NULL, *curr = slow;

    while (curr) {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Find maximum twin sum
    int ans = 0;
    ListNode *first = head;
    ListNode *second = prev;

    while (second) {
        ans = max(ans, first->val + second->val);
        first = first->next;
        second = second->next;
    }

    cout << ans << endl;

    return 0;
}