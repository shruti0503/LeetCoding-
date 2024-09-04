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

void dfs(TreeNode* root, vector<int>& num){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) num.push_back(root->val);
    dfs(root->left,num);
    dfs(root->right,num);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> num1;
        vector<int> num2;

        dfs(root1,num1);
        dfs(root2,num2);
        if(num1==num2) return true;
        else return false;

    }
};