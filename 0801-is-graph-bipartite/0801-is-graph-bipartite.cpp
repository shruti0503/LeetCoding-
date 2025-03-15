class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, int col) {
        color[node] = col;  // Color the current node

        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) {  // If uncolored, color it with opposite color
                if (!dfs(neighbor, graph, color, 1 - col)) return false;
            } 
            else if (color[neighbor] == color[node]) {  // If same color as current node, not bipartite
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // -1 means uncolored

        for (int i = 0; i < n; i++) {  // Check for each component
            if (color[i] == -1) {
                if (!dfs(i, graph, color, 0)) return false;
            }
        }
        return true;
    }
};