#include<iostream>
using namespace std;

// Define Node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    bool isPalindrome(Node *head) {
        if (head == NULL || head->next == NULL)
            return true;

        // Step 1: Find middle
        Node* slow = head;
        Node* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        Node* prev = NULL;
        Node* curr = slow->next;

        while (curr) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Step 3: Compare
        Node* first = head;
        Node* second = prev;

        while (second) {
            if (first->data != second->data)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};

// ✅ main should be outside
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);

    Solution obj;
    cout << obj.isPalindrome(head);

    return 0;
}