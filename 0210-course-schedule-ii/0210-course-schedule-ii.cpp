class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& inStack, stack<int>& st) {
        // If the node is already in the current recursion stack, it's a cycle
        if (inStack[node]) return false;
        
        // If it's already visited, no need to explore again
        if (vis[node]) return true;

        // Mark the node as visited and add to the recursion stack
        vis[node] = 1;
        inStack[node] = 1;

        // Explore all the adjacent nodes
        for (auto it : adj[node]) {
            if (!dfs(it, adj, vis, inStack, st)) {
                return false;
            }
        }

        // After finishing this node, push it to the stack and remove from the recursion stack
        inStack[node] = 0;
        st.push(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // adjacency list
        vector<int> vis(numCourses, 0);  // to mark nodes as visited
        vector<int> inStack(numCourses, 0);  // to mark nodes in the current DFS path
        stack<int> st;  // stack to store the topological order
        
        // Build the graph (adjacency list)
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        // Try to find a valid topological sort using DFS
        for (int i = 0; i < numCourses; ++i) {
            if (!vis[i]) {
                if (!dfs(i, adj, vis, inStack, st)) {
                    return {};  // If there's a cycle, return an empty array
                }
            }
        }

        // Collect the result from the stack
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
