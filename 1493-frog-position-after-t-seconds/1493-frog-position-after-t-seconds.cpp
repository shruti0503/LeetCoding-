class Solution {
public:
    
double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    // Build the adjacency list
    vector<vector<int>> graph(n + 1);
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    // BFS queue: {current node, probability, time elapsed}
    queue<pair<int, pair<double, int>>> q;
    q.push({1, {1.0, 0}});
    vector<bool> visited(n + 1, false);
    visited[1] = true;

    while (!q.empty()) {
        auto [node, prob_time] = q.front();
        auto [prob, time] = prob_time;
        q.pop();

        // Stop traversal if time exceeds t
        if (time > t) continue;

        // If at target node and time == t or no more neighbors to jump
        if (node == target) {
            if (time == t || graph[node].size() == (node == 1 ? 0 : 1)) {
                return prob;
            }
        }

        // Calculate unvisited neighbors
        int unvisited_count = 0;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                unvisited_count++;
            }
        }

        // Add unvisited neighbors to the queue
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, {prob / unvisited_count, time + 1}});
            }
        }
    }

    return 0.0; // Target not reachable within t seconds
}
};
