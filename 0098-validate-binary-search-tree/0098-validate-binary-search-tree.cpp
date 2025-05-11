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
    bool func(TreeNode* root,long minVal,long maxVal){
         if(!root)   return true;
        if(root->val >=maxVal || root->val<=minVal) return false;

        return func(root->left, minVal, root->val) && func(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return func(root, LONG_MIN, LONG_MAX);
    }
};