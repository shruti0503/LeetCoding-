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
    bool isPalindrome(ListNode* head) {

        if(!head || !head->next){
            return true;
        }
        // 1->2->2->1
        // middle of ll
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        } // mid=2
        // reverse first half
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=slow){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        } // <-1<-2 2->1
        // for odd length
        if(fast){
            slow=slow->next;
        }
        // compare two halves of ll
        while(prev and slow){
            if(prev->val != slow->val){
                return false;
            }
            prev=prev->next;
            slow=slow->next;
        }
        return true;

        
    }
};