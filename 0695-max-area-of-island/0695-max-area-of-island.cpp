

class Solution {
public:
    int bfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& vis) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> pq;
        pq.push({r, c});
        vis[r][c] = true;
        int ans = 1; // Start with 1 as we are including the starting cell

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!pq.empty()) {
            auto [i, j] = pq.front();
            pq.pop();

            for (auto dir : directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;

                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == 1 && !vis[ni][nj]) {
                    pq.push({ni, nj});
                    vis[ni][nj] = true;
                    ans++;
                }
            }
        }
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0; // Initialize to 0 to handle cases with no islands

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    ans = max(ans, bfs(grid, i, j, vis));
                }
            }
        }

        return ans;
    }
};