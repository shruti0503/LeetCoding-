/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val === undefined ? 0 : val);
 *     this.next = (next === undefined ? null : next);
 * }
 */

var addTwoNumbers = function(l1, l2) {
    let carry = 0;
    let dummy = new ListNode();
    let temp = dummy;
    
    while (l1 !== null || l2 !== null || carry !== 0) {
        let sum = carry;
        
        if (l1 !== null) {
            sum += l1.val;
            l1 = l1.next;
        }
        
        if (l2 !== null) {
            sum += l2.val;
            l2 = l2.next;
        }
        
        carry = Math.floor(sum / 10);
        temp.next = new ListNode(sum % 10);
        temp = temp.next;
    }
    
    return dummy.next;
};
