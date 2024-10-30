class Solution {
public:
  void  dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis){
    vis[node]=1;
    for(int i=0;i<isConnected[node].size();i++){
        if(isConnected[node][i] and !vis[i]){
            dfs(i, isConnected,vis);
        }
    }
  }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // isConncetd is the graph , that shows connectoon
        // and isCOnnected.size() is the numbver of vertices we have
        int n=isConnected.size();
        int m=isConnected.size();
        vector<int>vis(n,0);
        int cnt=0;

        for(int i=0;i<isConnected.size();i++){
            if(vis[i]!=1){
                dfs(i,isConnected, vis);
                cnt++;

            }
        }

        return cnt;
    }
};