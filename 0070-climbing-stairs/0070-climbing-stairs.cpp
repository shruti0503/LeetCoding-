class Solution {
public:
    int func(vector<int>& dp, int n){
        if(n==1 || n==0) return 1;
        if(dp[n]!=0) return dp[n];
        dp[n]= func(dp,n-1) + func(dp,n-2);

        return dp[n];

    }
    int climbStairs(int n) {
        if(n == 1) return 1; 
        // if(n==1 || n==0) return 1;
        // return climbStairs(n-1) + climbStairs(n-2);
        vector<int>dp(n+1, 0);

        func(dp,n);
        return dp[n];
        
    }
};