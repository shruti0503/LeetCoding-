class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int v=rooms.size();
        vector<int> vis(v,0);

        
                dfs(0,vis,rooms);
        

        for(int i=0;i<vis.size();i++){
            if(vis[i]==0){
                return false;
            }

        }
        return true;
        
    }
};