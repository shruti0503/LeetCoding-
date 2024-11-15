class Solution {
public:
   int func(int right, int down, int m , int n,vector<vector<int>>& dp){
            if(right>n-1 || down>m-1){
                return 0;
            }
            if(right==n-1 and down==m-1){
                return 1;
            }
            if(dp[down][right]!=-1){
                return dp[down][right];
            }

        return dp[down][right]=func(right+1, down , m, n, dp)+func(right, down+1, m, n,dp);
   }
   int tab(int m , int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[m-1][n-1] = 1; // Set the destination cell

    for(int i = m - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if (i == m - 1 && j == n - 1) continue; // Skip destination cell

            int down = 0;
            if (i + 1 < m) { // Check within row boundaries for down move
                down = dp[i + 1][j];
            }

            int right = 0;
            if (j + 1 < n) { // Check within column boundaries for right move
                right = dp[i][j + 1];
            }

            dp[i][j] = right + down; // Sum paths from right and down
        }
    }

    return dp[0][0]; // Result: paths from top-left to bottom-right
}

   
    int uniquePaths(int m, int n) {

         vector<vector<int>> dp(m, vector<int>(n, -1));
       // return func(0, 0, m, n, dp);
      return tab(m, n);
        
    }
};