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
    int minimumOperations(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode* > pq;
        pq.push(root);
        int totalSwaps=0; 
        while(!pq.empty()){
            int size=pq.size();
            // current level ki values
            vector<int> levelValues;

            for(int i=0;i<size;i++){
                TreeNode* node=pq.front();
                pq.pop();
                levelValues.push_back(node->val);
                if(node->left){
                    pq.push(node->left);
                }
                if(node->right){
                    pq.push(node->right);
                }
                
            }
            // for curr level , calc minimum swaps
             totalSwaps+=countMinSwaps(levelValues);
        }

        return totalSwaps;

    }

    int countMinSwaps(vector<int>& arr){
        int n=arr.size();
        vector<pair<int,int>>valueIndex; // {value, index}

        for(int i=0;i<n;i++){
            valueIndex.push_back({arr[i], i});
        }
        sort(valueIndex.begin(), valueIndex.end()); // sort on baisis-> value -> 
        vector<bool> visited(n, false);
        int swaps=0;
        for(int i=0;i<n;i++){
            // check if alreasy visisted aur agar pehele se correct position mai toh nhi hg
            if(visited[i] || valueIndex[i].second==i) continue;
            int cycleSize=0;
            int j=i;

            while(!visited[j]){ // 
                visited[j]=true;
                j=valueIndex[j].second;
                cycleSize++;
            }
            if(cycleSize>1){
                swaps+=(cycleSize-1);
            }
        }
        return swaps;
    }
};