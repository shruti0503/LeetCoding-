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
   
    int uniquePaths(int m, int n) {

         vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(0, 0, m, n, dp);
        
    }
};