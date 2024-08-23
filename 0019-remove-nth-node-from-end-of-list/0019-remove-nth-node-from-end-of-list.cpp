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
      ListNode* d=new ListNode();
      ListNode* fast;
      ListNode* slow;
      d->next=head;
      fast=slow=d;
      for(int i=0;i<n;i++){
        fast=fast->next;
      }      
      while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
      }
      //dlete the node
      slow->next=slow->next->next;
      return d->next;
    }
};