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
   int d=0;
   int calc(TreeNode* root){
    if (!root) return 0;
    int lh=calc(root->left);
    int rh=calc(root->right);
    d=max(d, lh+rh);
    return 1+max(lh, rh);

   }
    int diameterOfBinaryTree(TreeNode* root) {
        calc(root);
        return d;  
    }
};