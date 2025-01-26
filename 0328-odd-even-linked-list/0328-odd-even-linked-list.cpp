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
    ListNode* oddEvenList(ListNode* head) {
        // 1->2->3->4->5
        // ptr1
        // 1->3
        // 2->4
             if (!head || !head->next) {
            return head;
        }
        ListNode* ptr1=head; // 
        ListNode* newHead=head;
        ListNode* ptrhead;
 
        ListNode* ptr2=head->next; // 
        ptrhead=ptr2; //

        while(ptr2 and ptr2->next){
            ListNode* temp1=ptr1->next->next;
            ListNode* temp2=ptr2->next->next;

            ptr1->next=ptr1->next->next;
            ptr2->next=ptr2->next->next;
            ptr1= ptr1->next;
            ptr2= ptr2->next;
        }

        ptr1->next=ptrhead;

        return head;

        
    }
};