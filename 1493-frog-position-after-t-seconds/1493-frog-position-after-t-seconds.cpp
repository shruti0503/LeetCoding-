class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>>graph(n+1);
        for(auto& edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        //  for(auto& edge:edges){
        //     // cout<<"adj nodes for "<<edge
        //     for(auto it:edge){
        //         cout<<"graph is "<<it<< endl;

        //     }
            
        // }
       
        queue<pair<int, pair<double, int>>>q; // node , [probab, time]
        q.push({1,{1.0,0}});
    
        vector<bool>vis(n+1, false);
        vis[1]=true;

        while(!q.empty()){
            auto [node, probab_time]=q.front();
            auto [probab, time]=probab_time;
            q.pop();
            if(time>t){
                cout<<"stopping traversal as time exceeded, curr time is : "<<time<<endl;
                continue;
            }
            if(node==target){ // If at target node and time == t or no more neighbors to jump
                cout<<"node==target so , time is "<< time << " and graph[node].size() is  "<<graph[node].size()<<endl;
                if(time==t || graph[node].size()==(node==1?0:1)){
                    return probab;
                }
            }
            int unvisited=0;
            for(int adj:graph[node]){
                if(!vis[adj]){
                    unvisited++;
                }
            }

            for (int neighbor : graph[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                q.push({neighbor, {probab / unvisited, time + 1}});
            }
          }
        }

        return 0.0;

        
    }
};