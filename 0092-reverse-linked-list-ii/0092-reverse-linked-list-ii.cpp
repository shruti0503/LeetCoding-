/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;  // No need to reverse a single node.

        ListNode* dummy = new ListNode(0);  // Create a dummy node to handle cases where 'left' is 1.
        dummy->next = head;
        ListNode* prev = dummy;  // The node before the left boundary.
        int i = 1;

        while (i < left) {
            prev = prev->next;
            i++;
        }

        // 'prev' is now at the node before the left boundary.
        ListNode* current = prev->next;  // The node at the left boundary.
        ListNode* next = nullptr;  // The node after 'current'.

        while (i < right) {
            next = current->next;
            current->next = next->next;  // Adjust pointers to reverse the link.
            next->next = prev->next;
            prev->next = next;
            i++;
        }

        return dummy->next;  // Return the modified list.
    }
};
