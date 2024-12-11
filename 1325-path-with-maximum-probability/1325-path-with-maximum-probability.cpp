class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //start to end 
        // path with the maximum probabiyt of succes going front start to end 
          // Step 1: Build adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            
            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }

        // Step 2: Use a priority queue to store (probability, node)
        priority_queue<pair<double, int>> pq;
        // Start with probability 1 at the start node
        pq.push({1.0, start}); 

        // Step 3: Probability array
        vector<double> probability(n, 0.0);
        probability[start] = 1.0;

        while (!pq.empty()) {
            auto [currProb, currNode] = pq.top();
            pq.pop();

            // If we've reached the target node, return the probability
            if (currNode == end) {
                return currProb;
            }

            // Process neighbors
            for (auto& [neighbor, edgeProb] : graph[currNode]) {
                double newProb = currProb * edgeProb;
                // Update probability if we find a better path
                if (newProb > probability[neighbor]) {
                    probability[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }

        // If we never reach the end node
        return 0.0;
    }
};