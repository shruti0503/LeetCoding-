class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        
        queue<pair<pair<int, int>, int>> pq; // Queue to store {position, time}
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Initialize the queue with initial rotten oranges and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    pq.push({{i, j}, 0});
                    vis[i][j] = 2; // Mark as rotten in visited array
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // Directions for movement (up, right, down, left)
        vector<pair<int, int>> del = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        // BFS traversal
        while (!pq.empty()) {
            auto [pos, currTime] = pq.front();
            int row = pos.first;
            int col = pos.second;
            pq.pop();

            time = max(time, currTime); // Update the time to the current max level

            // Explore neighbors
            for (auto [dRow, dCol] : del) {
                int nRow = row + dRow;
                int nCol = col + dCol;

                // Check boundaries and whether the orange is fresh
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && vis[nRow][nCol] != 2) {
                    pq.push({{nRow, nCol}, currTime + 1});
                    vis[nRow][nCol] = 2; // Mark as rotten
                    fresh--; // Decrease the count of fresh oranges
                }
            }
        }

        // If there are any fresh oranges left, return -1
        return fresh == 0 ? time : -1;
    }
};
