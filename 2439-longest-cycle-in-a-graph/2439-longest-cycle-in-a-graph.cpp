class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false); // Tracks nodes already fully processed
        vector<int> depth(n, -1);      // Tracks the depth of each node in the DFS path
        int maxCycleLength = -1;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, edges, visited, depth, maxCycleLength, 0);
            }
        }

        return maxCycleLength;
    }

private:
    void dfs(int node, vector<int>& edges, vector<bool>& visited, vector<int>& depth, int& maxCycleLength, int currentDepth) {
        if (node == -1) return; // No outgoing edge
        if (depth[node] != -1) {
            // Node already visited in the current path, cycle detected
            maxCycleLength = max(maxCycleLength, currentDepth - depth[node]);
            return;
        }
        if (visited[node]) return; // Node already fully processed, skip it

        // Mark the node as visited in the current DFS path
        depth[node] = currentDepth;

        // Recursive call to the next node
        dfs(edges[node], edges, visited, depth, maxCycleLength, currentDepth + 1);

        // Mark the node as fully processed and remove it from the current path
        visited[node] = true;
        depth[node] = -1;
    }
};
