class Solution {
public:
     // TC: O(N) sc O(N)
     int solve(vector<int>& cost, int n, vector<int>& dp){
        if (n==0) return cost[0]; 
        if(n==1) return cost[1];

        if(dp[n]!=-1) return dp[n];

        int ans=cost[n]+min(solve(cost, n-1,dp), solve(cost, n-2,dp));
        dp[n]=ans;
        return ans;
     }
     int tab(vector<int>& cost, int n){
        vector<int>dp(n+1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=cost[i] + min(dp[i-1],dp[ -2]);
        }
        return min(dp[n-1], dp[n-2]);
     }
      int spaceOpt(vector<int>& cost, int n){
        
        int prev2=cost[0];
        int prev1=cost[1];
        for(int i=2;i<n;i++){
            int curr=cost[i]+min(prev1, prev2);
           prev2=prev1;
           prev1=curr;
        }
        return min(prev1, prev2);
     }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1, -1);
        int ans=min(solve(cost,n-1, dp), solve(cost, n-2, dp)); // one starting from 1st step , and other from 2nd 
       // return ans;
      // return tab(cost, n);

      return spaceOpt(cost, n);
        
    }
};