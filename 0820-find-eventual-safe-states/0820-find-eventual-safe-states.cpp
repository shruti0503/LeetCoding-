class Solution {
public:
    // Helper function to perform DFS
        bool dfs(int node, vector<vector<int>>& graph, vector<int>& states) {
            if (states[node] == 1) {  // If the node is currently being visited, it means we've found a cycle.
                return false;
            }
            if (states[node] == 2) {  // If the node is already safe, no need to visit again.
                return true;
            }
            
            states[node] = 1;  // Mark as visiting
            
            // Explore all adjacent nodes
            for (int neighbor : graph[node]) {
                if (!dfs(neighbor, graph, states)) {
                    return false;
                }
            }
            
            states[node] = 2;  // Mark as safe
            return true;
        }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> states(n, 0);  // States: 0 = unvisited, 1 = visiting, 2 = safe
        vector<int> safeNodes;
        
        // Perform DFS for all nodes
        for (int i = 0; i < n; i++) {
            if (states[i] == 0) {  // If the node is unvisited
                dfs(i, graph, states);
            }
        }
        
        // Collect safe nodes
        for (int i = 0; i < n; i++) {
            if (states[i] == 2) {
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};
