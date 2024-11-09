class Solution {
public:
   bool checkCycle(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& inDfs) {
     vis[node] = 1;
     inDfs[node] = 1;

     for (int neighbor : adj[node]) {
        if (!vis[neighbor]) { // If not visited, explore the neighbor
            if (checkCycle(neighbor, adj, vis, inDfs)) return true;
        } else if (inDfs[neighbor]) { // If the neighbor is in the current DFS path, we found a cycle
            return true;
        }
     }
     inDfs[node] = 0; // Backtrack and mark as not in DFS path
     return false; 
   }

   bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0); // To keep track of visited nodes
        vector<int> inDfs(numCourses, 0); // To keep track of nodes in the current DFS path

        // Build the adjacency list
        for (auto& task : prerequisites) {
            int course = task[0];
            int pre = task[1];
            adj[pre].push_back(course); // pre is a prerequisite for course
        }

        // Check for cycles starting from every course
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) { // If not yet visited, start DFS from this course
                if (checkCycle(i, adj, vis, inDfs)) {
                    return false; // Cycle detected, so we can't finish all courses
                }
            }
        }

        return true; // No cycles, all courses can be finished
    }
};
