/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int search(TreeNode* curr,int max){
        if(!curr) return 0;
        int cnt=0;
        if(curr->val>=max){
            cnt++;
            max=curr->val;
        }
        cnt+=search(curr->left,max);
        cnt+=search(curr->right,max);
        return cnt;

    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int goodNodes=1;
        goodNodes+=search(root->left,root->val);
        goodNodes+=search(root->right,root->val);
        return goodNodes;
    }
};