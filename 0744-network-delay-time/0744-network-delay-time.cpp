

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Initialize adjacency list
        vector<vector<int>> adj[n + 1];
        for (const auto& time : times) {
            int src = time[0];
            int target = time[1];
            int weight = time[2];
            adj[src].push_back({target, weight});
        }

        // Min-heap priority queue (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // Distance vector initialized to infinity
        vector<int> dist(n + 1, INT_MAX);

        // Starting point
        dist[k] = 0;
        pq.push({0, k}); // (distance, node)

        while (!pq.empty()) {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // If the distance in the queue is greater than the current known distance, skip processing
            if (currDist > dist[node]) continue;

            // Traverse all neighbors
            for (const auto& neighbor : adj[node]) {
                int nextNode = neighbor[0];
                int weight = neighbor[1];

                // Relaxation step
                if (dist[node] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        // Find the maximum distance from the starting node to any node
        int maxDist = *max_element(dist.begin() + 1, dist.end());

        // If there is a node that is not reachable, return -1
        return maxDist == INT_MAX ? -1 : maxDist;
    }
};

// The time complexity of the solution using Dijkstra's algorithm can be analyzed as follows:

// ### Components of the Complexity

// 1. **Initialization**:
//    - Initializing the adjacency list and distance vector takes \(O(n)\).

// 2. **Building the Adjacency List**:
//    - This involves iterating over the `times` array, which has `E` elements (where `E` is the number of edges). Thus, building the adjacency list takes \(O(E)\).

// 3. **Priority Queue Operations**:
//    - Each node is pushed into the priority queue once and can be popped once, which is \(O(n \log n)\) due to the properties of a binary heap.
//    - For each node, we check its neighbors. In the worst case, we might check all edges, which means \(O(E \log n)\) for updating the priority queue (since each update takes \(O(\log n)\)).

// ### Total Time Complexity

// Combining these components, the total time complexity is:

// \[ O(n) + O(E) + O(n \log n) + O(E \log n) = O((n + E) \log n) \]

// ### Explanation

// - **Initialization**: Setting up the adjacency list and the distance vector requires linear time relative to the number of nodes, \(O(n)\).
// - **Building the Adjacency List**: This involves a single pass over the `times` array, which has \(E\) elements, taking \(O(E)\) time.
// - **Priority Queue Operations**: The primary operations with the priority queue (insertion and extraction) dominate the complexity. Each node is pushed and popped from the queue, each taking \(O(\log n)\) time. The neighbor updates, which are proportional to the number of edges, also contribute \(O(E \log n)\) to the complexity.

// Thus, the overall time complexity is \(O((n + E) \log n)\), where \(n\) is the number of nodes and \(E\) is the number of edges.

// ### Space Complexity

// The space complexity of the solution is dominated by:
// - The adjacency list, which takes \(O(E)\) space.
// - The distance vector and the priority queue, which together take \(O(n)\) space.

// Thus, the overall space complexity is \(O(n + E)\).

// ### Conclusion

// The solution using Dijkstra's algorithm with a priority queue is efficient for this problem and operates within the expected time complexity for graph algorithms that need to process all nodes and edges.