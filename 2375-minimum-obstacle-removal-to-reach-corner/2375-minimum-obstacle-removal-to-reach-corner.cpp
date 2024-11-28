#include <deque>


class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX)); 
        deque<pair<int, int>> dq; 

       
        dist[0][0] = 0;
        dq.push_front({0, 0});

       
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!dq.empty()) {
            auto [row, col] = dq.front();
            dq.pop_front();

            for (auto dir : directions) {
                int nrow = row + dir.first;
                int ncol = col + dir.second;

                // Check bounds
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newDist = dist[row][col] + grid[nrow][ncol];
                    if (newDist < dist[nrow][ncol]) { 
                        dist[nrow][ncol] = newDist;

                        // Push to front if no obstacle; to back otherwise
                        if (grid[nrow][ncol] == 0) {
                            dq.push_front({nrow, ncol});
                        } else {
                            dq.push_back({nrow, ncol});
                        }
                    }
                }
            }
        }

       
        return dist[n - 1][m - 1];
    }
};
