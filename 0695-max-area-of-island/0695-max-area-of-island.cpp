class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, func(n, m, i, j, grid, vis));
            }
        }
        return ans;
    }

    int func(int n, int m, int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if (row < 0 || row >= n || col < 0 || col >= m || vis[row][col] || grid[row][col] == 0) {
            return 0;
        }
        vis[row][col] = 1;
        int bottom = func(n, m, row + 1, col, grid, vis);
        int top = func(n, m, row - 1, col, grid, vis);
        int right = func(n, m, row, col + 1, grid, vis);
        int left = func(n, m, row, col - 1, grid, vis);
        return bottom + top + left + right + 1;
        //   The 1 is added to the result because the current cell i
        //  tself is a land cell, and it is part of the area of the island.
        //   The base case of the recursion, 
        //  when it returns 0, is for the cells that
        //   are not part of the island, so they don't contribute to
        //    the area count. However, when the cell is part of the island
        //   (i.e., when it returns from the recursive calls), we add 1 to the count to include the current cell in the area.
    }
};
