class Solution {
public:
   int solve(int iniStep, int steps, vector<int>& cost, vector<int>& dp) {
       // Base case: If we have reached the top or beyond, no cost is required.
       if (iniStep >= steps) return 0;

       if(dp[iniStep]!=-1){
         return dp[iniStep]; 
       }
       
       // Recursively calculate the minimum cost of taking one or two steps
       int oneStep = solve(iniStep + 1, steps, cost,dp) + cost[iniStep];
       int twoStep = solve(iniStep + 2, steps, cost,dp) + cost[iniStep];

       // Return the minimum cost between taking one or two steps
        dp[iniStep]= min(oneStep, twoStep);
        return dp[iniStep];
   }

   int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size(); // number of steps

       vector<int>dp(n+1, -1);
       
       // Start from step 0 or step 1, and take the minimum cost to reach the top
       return min(solve(0, n, cost,dp), solve(1, n, cost,dp));
   }
};
