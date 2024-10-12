/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        unordered_map<Node* , Node*> mpp;
        while(temp!=NULL){
            Node* newNode=new Node(temp->val); // new node with same data
            mpp[temp]=newNode; // 7,7
            temp=temp->next; // move forward in the original linked list
        }
        temp=head;
        //connect the next random pointers of the copied nodes using the map
        while(temp!=NULL){
            Node* copyNode=mpp[temp];
            copyNode->next=mpp[temp->next];
            copyNode->random = mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];
        
    }
};