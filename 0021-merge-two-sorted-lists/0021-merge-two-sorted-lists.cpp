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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();  // Dummy node to simplify the handling of the head of the merged list
        ListNode* curr = dummy;  // Pointer to build the merged list
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;  // Attach the smaller node to the merged list
                list1 = list1->next;  // Move to the next node in list1
            } else {
                curr->next = list2;  // Attach the smaller node to the merged list
                list2 = list2->next;  // Move to the next node in list2
            }
            curr = curr->next;  // Move the current pointer to the next node
        }
        
        // Attach the remaining part of the list that is not yet exhausted
        if (list1 != nullptr) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }
        
        return dummy->next;  // Return the merged list starting from the first node
    }
};
