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
    
    ListNode* reverseList(ListNode* head, int k){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(k--){
            ListNode* next= curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* node=head;
        int count=0;

        while(node && count<k){
            node=node->next;
            count++;
        }
        if(count<k) return head;
        ListNode* newHead=reverseList(head,k);
        head->next=reverseKGroup(node,k);
        return newHead;
        
    }
};