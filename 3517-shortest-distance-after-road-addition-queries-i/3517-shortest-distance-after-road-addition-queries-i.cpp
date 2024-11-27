class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n); 
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1); 
        }

        vector<int> ans;

        for (const auto& query : queries) {
            adj[query[0]].push_back(query[1]);

            queue<pair<int, int>> pq; // {current_node, steps}
            pq.push({0, 0});
            vector<int> vis(n, 0);
            vis[0] = 1;

            bool found = false;
            while (!pq.empty()) {
                auto [node, steps] = pq.front();
                pq.pop();

                if (node == n - 1) {
                    ans.push_back(steps);
                    found = true;
                    break;
                }

                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;  // mark as visited
                        pq.push({it, steps + 1});
                    }
                }
            }

            if (!found) {
                ans.push_back(-1); 
            }
        }

        return ans;
    }
};
