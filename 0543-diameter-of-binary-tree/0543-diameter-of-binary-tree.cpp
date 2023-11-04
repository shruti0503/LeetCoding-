// BRUTE FORCE APPRoACH
class Solution {
public:
    int findHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
    
    int findDiameter(TreeNode* root, int& maxDiameter) {
        if (!root) {
            return 0;
        }
        
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        int currentDiameter = leftHeight + rightHeight;
        
        maxDiameter = max(maxDiameter, currentDiameter);
        
        int leftDiameter = findDiameter(root->left, maxDiameter);
        int rightDiameter = findDiameter(root->right, maxDiameter);
        
        return max(leftDiameter, rightDiameter) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        findDiameter(root, maxDiameter);
        return maxDiameter;
    }
};