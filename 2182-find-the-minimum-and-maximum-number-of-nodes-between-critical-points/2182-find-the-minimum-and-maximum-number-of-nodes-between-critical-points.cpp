

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        if (!head || !head->next || !head->next->next) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int pos = 1;
        int firstCriticalPos = -1;
        int lastCriticalPos = -1;
        int minDist = INT_MAX;

        while (next) {
            if ((curr->val > prev->val && curr->val > next->val) || 
                (curr->val < prev->val && curr->val < next->val)) {
                if (firstCriticalPos == -1) {
                    firstCriticalPos = pos;
                } else {
                    minDist = min(minDist, pos - lastCriticalPos);
                }
                lastCriticalPos = pos;
            }
            prev = curr;
            curr = next;
            next = next->next;
            pos++;
        }

        if (firstCriticalPos == -1 || lastCriticalPos == firstCriticalPos) {
            ans.push_back(-1);
            ans.push_back(-1);
        } else {
            ans.push_back(minDist);
            ans.push_back(lastCriticalPos - firstCriticalPos);
        }

        return ans;
    }
};
