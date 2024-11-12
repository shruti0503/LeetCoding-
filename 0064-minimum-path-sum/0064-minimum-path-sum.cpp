class Solution {
public:

   int func(vector<vector<int>>& grid, int row, int col ,int n , int m,vector<vector<int>>& dp){
     if (row >= n || col >= m ) return INT_MAX;
     if(row==n-1 and col==m-1) return grid[row][col];
     if(dp[row][col]!=-1) return dp[row][col];

     int right=INT_MAX;
     int down=INT_MAX;

     if(row<n-1){
         down = grid[row][col] + func(grid, row + 1, col, n, m, dp);
     }
     if(col<m-1){
         right=grid[row][col] + func(grid, row, col+1, n, m, dp);

     }


      dp[row][col]=min(down, right);
      return dp[row][col];

   }

   int tab(vector<vector<int>>& grid){
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>> dp(n, vector<int>(m, INT_MAX)); 
      dp[n-1][m-1]=grid[n-1][m-1];

      for (int row = n - 1; row >= 0; row--) {
        for (int col = m - 1; col >= 0; col--) {
            // Calculate right and down costs if within bounds
            int right = (col + 1 < m) ? dp[row][col + 1] : INT_MAX;
            int down = (row + 1 < n) ? dp[row + 1][col] : INT_MAX;

            // Only update if it's not the destination cell
            if (row != n - 1 || col != m - 1) {
                dp[row][col] = grid[row][col] + min(right, down);
            }
        }
    }

      return dp[0][0];

   }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1)); 
    //return func(grid, 0, 0, n, m, dp);
    return tab(grid);
        
    }
};