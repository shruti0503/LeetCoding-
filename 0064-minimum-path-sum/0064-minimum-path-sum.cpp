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
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1)); 
    return func(grid, 0, 0, n, m, dp);
        
    }
};