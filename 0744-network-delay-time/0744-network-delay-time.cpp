class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

      
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k}); // (time, node)

        vector<int> dist(n + 1, INT_MAX); 
        dist[k] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int currTime = curr.first;
            int node = curr.second;

           
            if (currTime > dist[node]) continue;

            for (auto neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int weight = neighbor.second;

                if (dist[node] + weight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + weight;
                    pq.push({dist[adjNode], adjNode}); 
                }
            }
        }

       
        int maxDist = *max_element(dist.begin() + 1, dist.end());
        return maxDist == INT_MAX ? -1 : maxDist;
    }
};
