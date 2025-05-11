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
    TreeNode* LastRight(TreeNode* root) {
        if (root == nullptr) return nullptr;
        if (root->right == nullptr) return root;
        return LastRight(root->right);
    }

    TreeNode* helper(TreeNode* root) {
        if (root->left == nullptr) return root->right;
        else if (root->right == nullptr) return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = LastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key) return helper(root);

        TreeNode* dum = root;
        TreeNode* parent = nullptr;

        while (root != nullptr) {
            if (root->val > key) {
                parent = root;
                root = root->left;
            } else if (root->val < key) {
                parent = root;
                root = root->right;
            } else {
                break;
            }
        }

        if (root == nullptr) return dum;

        if (parent->left == root)
            parent->left = helper(root);
        else
            parent->right = helper(root);

        return dum;
    }
};
