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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* node=head;

        // 1-> 2-> 3-> 4
        // n.  ni  
        // n->next=prev
        // prev=n
        // n=ni

        while(node!=NULL){
             ListNode* nextNode=node->next;
            node->next=prev;
            prev=node;
            node=nextNode;
            
        }
        return prev;
        
    }
};