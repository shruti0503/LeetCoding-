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
    
    void func(TreeNode* root, int& cnt, int k, int& smallest){

        if(!root || cnt>=k) return;

        func(root->left, cnt, k, smallest);
        cnt++;
        cout<<"small"<< smallest;
         cout<<"cnt"<< cnt;
        if(cnt==k){
            smallest =root->val;
            return;
        }

        func(root->right, cnt, k, smallest);

    }
    int kthSmallest(TreeNode* root, int k) {
        int smallest = 0; // Initialize smallest
        int cnt=0;
        func(root, cnt, k, smallest);

        return smallest;
        
    }
};
