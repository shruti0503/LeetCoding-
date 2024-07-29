class Solution {
public:
     
     int solve(vector<int>& cost, int n, vector<int>& dp){
        if (n==0) return cost[0];
        if(n==1) return cost[1];

        if(dp[n]!=-1) return dp[n];

        int ans=cost[n]+min(solve(cost, n-1,dp), solve(cost, n-2,dp));
        dp[n]=ans;
        return dp[n];
     }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1, -1);
        int ans=min(solve(cost,n-1, dp), solve(cost, n-2, dp)); // one starting from 1st step , and other from 2nd 
        return ans;
        
    }
};