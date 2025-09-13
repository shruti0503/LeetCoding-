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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,multiset<int>>>mpp; // {vertical[level]: [set of node values ([lvl]:node)]}
        queue<pair<TreeNode*,pair<int,int>>>pq; // {TreeNode,  { xPosition , yPosition} }
        pq.push({root,{0,0}});
        while(!pq.empty()){
            auto item=pq.front();
            pq.pop();
            TreeNode* node=item.first;
            int x=item.second.first;
            int y=item.second.second;
            mpp[x][y].insert(node->val);
            if(node->left){
                pq.push({node->left,{x-1, y+1}});
            }
            if(node->right){
                pq.push({node->right, {x+1, y+1}});
            }
        }

       vector<vector<int>> ans;
        for(auto q:mpp){
            vector<int> col;
            for(auto p:q.second){
                for (int val : p.second) {
                    col.push_back(val);
                }
            }
            ans.push_back(col);
        }
        return ans;

        
    }
};