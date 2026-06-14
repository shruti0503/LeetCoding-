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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // Find the middle node
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }  // slow is our mid

        // Reverse the first half of the linked list
        ListNode* nextNode;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != slow) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;

        int maximumSum = 0;
        ListNode* start = head;
        // Traverse both halves and find the maximum twin sum
        while (slow) {
            maximumSum = max(maximumSum, start->val + slow->val);
            slow = slow->next;
            start = start->next;
        }

        return maximumSum;
    }
};