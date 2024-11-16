class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& pathVis, vector<int>& vis, vector<int>& safeNode){
         vis[node]=1;
          pathVis[node] = 1; 

         for(auto adj:graph[node]){
            if(!vis[adj]){
               if( dfs(graph, adj, pathVis,vis , safeNode)){
                 safeNode[node]=-1; //The purpose of safeNodes[node] = -1 is to indicate that node itself is unsafe because it leads to a cycle either directly or indirectly through one of its adjacent nodes (adj). Since node is calling the DFS on adj, any cycle detected in adj means that node is also part of an unsafe path.
                 return true;
               } 
            }
            else if(pathVis[adj]){
                safeNode[node]=-1;
                return true;
            }
         }

         pathVis[node]=0;
         safeNode[node]=1;
         return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        vector<int> safeNodes(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph, i, pathVis, vis,safeNodes);
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safeNodes[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};