class Solution {
public:

    bool dfs(int current, int target, vector<bool>& visited, vector<vector<int>>& adj){
        if(current==target){
            return true;
        }
        visited[current]=true;
        for(int neighbor:adj[current]){
            if(!visited[neighbor]){
                if(dfs(neighbor, target, visited, adj)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // build adjList
        // process ea ch query using dfs
        // check if v is reachable
        vector<vector<int>>adj(numCourses);
        vector<bool>visited;
        for(auto pre:prerequisites){
            // 0 ,1 
            adj[pre[0]].push_back(pre[1]);
        }
        vector<bool>result;
        for(auto& query:queries){
            int u=query[0];
            int v=query[1];
            visited.assign(numCourses, false);// Reset visited for each query
            // Check if v is reachable from u
            bool res=dfs(u,v,visited,adj);
            result.push_back(res);
        }
        return result;


    }
};