class Solution {
public:
    int func(int n, int step, vector<int>& dp){
        // base case that i have reached the end 
        if(step==n){
            return 1;
        }
        if (step > n) return 0;
        if(dp[step]!=-1) return dp[step];
        int two=func(n, step+2,dp);
        // take one step
        int one=func(n, step+1,dp);
        return dp[step]=one+two;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return func(n, 0, dp);
        
    }
};