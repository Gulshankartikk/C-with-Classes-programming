#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if (head == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Find start of cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};

// Create linked list
ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Create cycle at position pos (0-based)
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;

    ListNode* temp = head;
    ListNode* cycleNode = NULL;
    int index = 0;

    while (temp->next != NULL) {
        if (index == pos) cycleNode = temp;
        temp = temp->next;
        index++;
    }

    // connect tail to cycle node
    temp->next = cycleNode;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int pos;
    cin >> pos;

    // Create list
    ListNode* head = createList(arr, n);

    // Create cycle
    createCycle(head, pos);

    Solution obj;
    ListNode* result = obj.detectCycle(head);

    if (result == NULL) {
        cout << "No cycle" << endl;
    } else {
        cout << "Cycle starts at node with value: " << result->val << endl;
    }

    return 0;
}