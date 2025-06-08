class Solution {
public:

    void dfs(int root , int N, vector<int>& ans){
        if(root>N) return ;
        ans.push_back(root);
        for(int i=0;i<=9;i++){
            if(root*10+i>N) break;
            dfs(root*10+i, N, ans);
        }

    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for(int i=1;i<=9;i++){
            dfs(i, n, ans);
        }
        return ans;
        
    }
};