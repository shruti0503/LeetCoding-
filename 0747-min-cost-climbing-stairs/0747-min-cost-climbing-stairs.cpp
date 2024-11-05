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
 // two approaches -> for tab 0 ,1 to n  ; n to 0 ,1
 int tabEnd(vector<int>& cost){
    int n=cost.size();
    vector<int>dp (n+1,INT_MAX);
    dp[n]=0; // no cost for reaching the top beynd
    for(int i=n-1;i>=0;i--){
        dp[i]= dp[i+1]+cost[i];
        if(i+2<=n){
            dp[i]=min(dp[i], dp[i+2]+cost[i]);
        }
    }
     return min(dp[0], dp[1]);



 }
   int tabStart(vector<int>& cost){
     int n = cost.size(); // number of steps
      vector<int>dp (n+1,INT_MAX);
      dp[0]=cost[0];
      dp[1]=cost[1];
      for(int i=2;i<n;i++){
        dp[i]=min(dp[i-1], dp[i-2])+cost[i];
      }
      return min(dp[n-1], dp[n-2]); // becaquse we have the option to either come from 0 or 1 in the strating so thats why
      
   }

   int spaceOpt(vector<int>& cost){
    int n = cost.size();
    if (n == 0) return 0; // Edge case: no steps
    if (n == 1) return cost[0]; // Edge case: only one step

    int prev2 = cost[0]; // Cost to reach step 0
    int prev1 = cost[1]; // Cost to reach step 1
    int current;

    // Start from step 2 to step n-1
    for (int i = 2; i < n; i++) {
        current = cost[i] + min(prev1, prev2); // Calculate current cost
        prev2 = prev1; // Move prev1 to prev2
        prev1 = current; // Update prev1 to current
    }

    // Minimum cost to reach the top can be from either the last step or second last step
    return min(prev1, prev2);
   }

   int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size(); // number of steps

       vector<int>dp(n+1, -1);
       
       // Start from step 0 or step 1, and take the minimum cost to reach the top
       //return min(solve(0, n, cost,dp), solve(1, n, cost,dp));
       //return tabStart(cost);
       //return tabEnd(cost);
       return spaceOpt(cost);
   }
};
