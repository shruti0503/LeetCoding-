
class Solution {
public:
    // Function to calculate the number of reachable cities from a given source
    int countReachableCities(int source, int n, vector<vector<pair<int, int>>>& adj, int distanceThreshold) {
        vector<int> dist(n, INT_MAX);
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, source}); // {distance, node}

        while (!pq.empty()) {
            pair<int, int> current = pq.top();
            pq.pop();
            int currentDist = current.first; // weigth 
            int u = current.second; // node 

            if (currentDist > dist[u]) continue;

            for (pair<int, int> neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                int newDist = currentDist + weight;
                if (newDist <= distanceThreshold && newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }

        cout<<endl;
        

        int reachable = 0;
        for (int d : dist) {
            cout<<"dist "<< d <<endl;
            if (d <= distanceThreshold) ++reachable;
        }

        return reachable - 1; // Exclude the source itself
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Build the adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }

        int minReachable = INT_MAX, result = -1;

        for (int i = 0; i < n; ++i) {
            int reachable = countReachableCities(i, n, adj, distanceThreshold);
            cout<<"reachable from "<<i<<" -> "<<reachable<<endl;
            if (reachable < minReachable || (reachable == minReachable && i > result)) {
                minReachable = reachable;
                result = i;
            }
        }

        return result;
    }
};


