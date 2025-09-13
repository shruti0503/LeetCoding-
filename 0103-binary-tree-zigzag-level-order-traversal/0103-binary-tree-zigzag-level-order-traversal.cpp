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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> pq;
        pq.push(root);
        bool flag=true;
        while(!pq.empty()){
            int size=pq.size();
            vector<int>res(size);
            for(int i=0;i<size;i++){
                TreeNode* node=pq.front();
                pq.pop();
                int index;
                if(flag){
                    index=i;
                }
                else{
                    index=size-i-1;
                }
                res[index]=node->val;
                if(node->left) pq.push(node->left);
                if(node->right) pq.push(node->right);
                
                
            }
            flag=!flag;
            ans.push_back(res);

        }
        return ans;


        
    }
};