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

// class TreeNode {
// public:
//     int val;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int val) {
//         this->val = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// width= first position - last position +1

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return NULL;
        int ans=0;
        queue<pair<TreeNode* , int>>q; // storing Node and the number of node
        q.push({root, 0});
        while(!q.empty()){
            int size=q.size(); // size =1 
            int min=q.front().second-1; // min= 0
            int first , last; 
            for(int i=0;i<size;i++){
                long long curr=q.front().second; // 0-(-0) = 0
                TreeNode* node=q.front().first; // root node -> 1

                q.pop();

                if(i==0) first=curr;
                if(i==size-1) last=curr;

                if(node->left){
                    q.push({node->left, curr*2+1});
                }
                if(node->right){
                    q.push({node->right, curr*2+2});
                }

            }

            ans=max(ans,last-first+1);
        
        }

        return ans;
        
    }
};