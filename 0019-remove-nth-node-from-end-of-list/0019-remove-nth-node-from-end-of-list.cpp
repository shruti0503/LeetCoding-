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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy= new ListNode();
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=dummy;

        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        // 1-> 2-> 3-> 4->5
        //      f

        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }

        slow->next=slow->next->next;
        return dummy->next;

        
    }
};