class Solution {
public:
    int func(int n, int m, vector<vector<int>>& obstacleGrid,int i, int j, int& ways, vector<vector<int>>& dp){

        if( i>=n || j>=m || obstacleGrid[i][j]==1 ) return 0;

        if(i==n-1 and j==m-1){
            return 1;
        }

        if(dp[i][j]!=-1) return dp[i][j];
       
        // if there is an obstacle go back
        // take right
        int right=func(n, m, obstacleGrid, i, j+1,ways,dp);

        // go down
        int down=func(n, m, obstacleGrid, i+1, j,ways,dp);
       
       return dp[i][j]=right+down;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // two paramters are changing
        int ways;
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        // vector<vector<int>>dp(m, vector<int>(n,-1));
         vector<vector<int>> dp(n, vector<int>(m, -1));

       return func(n, m, obstacleGrid,0,0,ways,dp);
       
        
    }
        
    
};