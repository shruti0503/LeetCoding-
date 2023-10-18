class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // make adj c list
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<graph.size();i++){
            for(auto j:graph[i]){
                adj[i].push_back(j);
            }
        }

        // for loop to cover all components of the graph
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){ // mtlb visited nhi h vo 
                // check for bipa
                queue<pair<int,int>>q;
                q.push({i,0}); // pehel node ko color 0 se color kia 
                vis[0]=0;
                while(!q.empty()){
                    int node= q.front().first;
                    int color=q.front().second;
                    q.pop();
                    for(auto it:adj[node]){
                        if(vis[it]==-1){
                            vis[it]= !color;
                            q.push({it,vis[it]});
                        }
                         // neighbour colored with same color that of the current node
                         else if(vis[it]==color) return false;
                    }
                   

                }
            }
        }
        return true;
    }
};