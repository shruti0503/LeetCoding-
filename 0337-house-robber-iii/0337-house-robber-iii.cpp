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
  unordered_map<TreeNode* , int> memo;
    int rob(TreeNode* root) {
        // take case
        // take = root->val + rob(root->left->left)+ rob(root->left->right)+ rob(root->right->right) + rob(root->right->left);
        // not take = rob(root->left)+ rrob(oot->right)
        if(!root) return 0;
        if(memo.find(root)!=memo.end()){
            return memo[root];
        }

        int take = root->val;
        if (root->left) {
            take += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            take += rob(root->right->left) + rob(root->right->right);
        }


        int notTake=0;
        if(root->left){
            notTake+=rob(root->left);
        }
        if(root->right){
            notTake+=rob(root->right);
        }

        return memo[root]=max(take, notTake);
    }
};