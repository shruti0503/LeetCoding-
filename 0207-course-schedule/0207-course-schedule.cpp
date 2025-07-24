class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Initialize in-degree array and adjacency list
        // indeg[i] = number of prerequisites for course i
        // adjList[i] = list of courses that depend on course i
        vector<int> indeg(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
       
        // Step 2: Build the graph (adjacency list) and calculate in-degrees
        for (auto courses : prerequisites) {
            // courses[0] depends on courses[1]
            indeg[courses[0]]++; // Increment in-degree for courses[0]
            adjList[courses[1]].push_back(courses[0]); // Add edge courses[1] → courses[0]
        }

        // Step 3: Add all nodes with 0 in-degree to the queue
        // These nodes have no prerequisites, so we can start processing them
        queue<int> pq;
        for (int i = 0; i < indeg.size(); i++) {
            if (indeg[i] == 0) {
                pq.push(i); // Push nodes with no prerequisites
            }
        }

        // Step 4: Perform BFS-like traversal to process the nodes
        vector<int> topo; // Store the topological order
        while (!pq.empty()) {
            int node = pq.front(); // Get the node with in-degree 0
            pq.pop();
            topo.push_back(node); // Add it to the topological order

            // Reduce in-degree of its neighbors (dependent courses)
            for (auto adj : adjList[node]) {
                indeg[adj]--; // Remove the dependency
                if (indeg[adj] == 0) {
                    pq.push(adj); // If in-degree becomes 0, add to queue
                }
            }
        }

        // Print the topological order (optional, for debugging purposes)
        for (int i = 0; i < topo.size(); i++) {
           cout << topo[i] << " ";
        }

        // Step 5: Check if all nodes are processed
        // If the size of the topological order equals the number of courses, 
        // there is no cycle, and all courses can be finished
        return topo.size() == numCourses;
    }
};