class Solution {
public:
    void dfs(TreeNode* node, int level, vector<int>& ans) {
        if (!node) return;

        // First node we see at this level → add to answer
        if (level == ans.size()) {
            ans.push_back(node->val);
        }

        // Go right first, then left
        dfs(node->right, level + 1, ans);
        dfs(node->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};
