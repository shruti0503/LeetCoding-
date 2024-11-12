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

    int tab(vector<vector<int>>& obstacleGrid){
         int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
         vector<vector<int>> dp(n, vector<int>(m, 0));
          dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else{
                    if(i>0) dp[i][j]+=dp[i-1][j];
                    if(j>0) dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // two paramters are changing
        int ways;
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        // vector<vector<int>>dp(m, vector<int>(n,-1));
         vector<vector<int>> dp(n, vector<int>(m, -1));

       //return func(n, m, obstacleGrid,0,0,ways,dp);
       
       return tab(obstacleGrid);
        
    }
        
    
};