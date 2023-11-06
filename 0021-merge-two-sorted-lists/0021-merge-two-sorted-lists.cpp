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
        //if both the linked lists are null return null
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        ListNode* i= list1;
        ListNode* j=list2;
        ListNode* dummy=i;
        //now see which ones's first node is smaller
        
        if(list1->val>list2->val){
            dummy=j; j=j->next;
        } 
        else{ i=i->next;}

        ListNode* curr=dummy;


        while(i && j){
            
            if(i->val>j->val){
                curr->next=j;
                j=j->next;
                 

            }
            else {
                
                 curr->next=i;
                 i=i->next;

            }
            curr=curr->next;
           
        }

        //process the remaining

        if(i){
            curr->next=i;
        }
        else{
            curr->next=j;
        }
        return dummy;
    }
};