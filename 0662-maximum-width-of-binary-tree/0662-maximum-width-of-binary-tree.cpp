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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return NULL;
        int ans=0;
        queue<pair<TreeNode*,int>>pq;
        pq.push({root,0});
        int first, last;
        while(!pq.empty()){
            int size=pq.size();
            int min=pq.front().second; // 0
            for(int i=0;i<size;i++){
                TreeNode* node=pq.front().first;
                long long currIndex=pq.front().second-min; // 0
                pq.pop();
                if(i==0) first=currIndex;
                if(i==size-1) last=currIndex;
                if(node->left) pq.push({node->left, currIndex*2+1});
                if(node->right) pq.push({node->right, currIndex*2+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};