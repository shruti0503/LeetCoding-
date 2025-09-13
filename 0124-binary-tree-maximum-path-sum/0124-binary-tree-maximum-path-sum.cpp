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

    int  func(TreeNode* root,int& maxSum){
        if(!root) return 0;
        int ls=max(0,func(root->left,maxSum));
        int rs=max(0, func(root->right,maxSum));
        maxSum=max(maxSum, ls+rs+root->val);
        return root->val+max(ls, rs);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        func(root, maxSum);
        return maxSum;
    }
};