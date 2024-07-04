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
    ListNode* mergeNodes(ListNode* head) {
        // brute force 
        // z1 find -> find z2
        // take another l1 -> start with in between the present l1 and l2
        // store the sum in values sum make a node 

        // z1=z2

        // find anbother z2  -> and conrinue the same 

        // dummy node to help with the construictions of the lits construic

        ListNode* dummy=new ListNode();
        ListNode* current=dummy;
        ListNode* temp= head-> next; //pointer to traverse tge original list

        int sum=0;

        while(temp!=nullptr){
            if(temp->val==0){
                //when a zero is found, finalise the current sum and reset
                current->next= new ListNode(sum);
                current=current->next;
                sum=0;
            }
            else{
                // add the current in sum
                sum+=temp->val;
            }
            temp=temp->next;
        }
        //return the modified list starting from the first node
        return dummy->next;


        
    }
};