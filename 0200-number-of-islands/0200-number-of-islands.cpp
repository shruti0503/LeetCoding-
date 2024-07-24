class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        // Create a visited matrix to track visited cells
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        // Iterate over each cell in the grid
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                // If the cell contains '1' and has not been visited before
                if (grid[i][j] == '1' && !visited[i][j]) {
                    // Increment the count of islands
                    res++;
                    // Call the dfs function to explore and mark the connected cells
                    dfs(grid, i, j, visited);
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        // Base case: check for out of bounds or visited cells
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j]) {
            return;
        }

        // Mark the current cell as visited
        visited[i][j] = true;

        // Recursive calls to explore the adjacent cells
        dfs(grid, i - 1, j, visited); // Up
        dfs(grid, i + 1, j, visited); // Down
        dfs(grid, i, j - 1, visited); // Left
        dfs(grid, i, j + 1, visited); // Right
    }
};
