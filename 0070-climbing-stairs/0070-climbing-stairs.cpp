class Solution {
public:
    int func(vector<int>& dp , int n){
        if(n==1 or n==0) return 1;
        if(dp[n]!=0) return dp[n];
        dp[n]=func(dp, n-1)+func(dp, n-2);
        return dp[n];
    }
    int tab(int n){
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            if(i==1){
                dp[i]=dp[i-1];
            }
            else{
                dp[i]=dp[i-1]+dp[i-2];
            }

        }
        return dp[n];


    }
    int climbStairs(int n) {
        if(n==1) return 1;
        vector<int>dp(n+1, 0);
        return tab(n);
        //return dp[n];
    }
};