class Solution {
public:
   int func(vector<vector<int>>& mat, int n , int m, int row , int col,vector<vector<int>>& dp){

    if(row==n-1) return mat[n-1][col];

   if (dp[row][col] != -1) return dp[row][col];

    int down= mat[row][col]+ func(mat, n, m, row+1,col, dp);
    int diagonal= mat[row][col]+func(mat, n, m, row+1, col+1,dp);

    return  dp[row][col]=min(down, diagonal);

   }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
        vector<vector<int>>dp(n+1, vector<int>(n+2,-1));
        return func(triangle, n ,m, 0, 0,dp);
        
        
    }
};