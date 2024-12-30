class Solution {
public:
  int mod=1e9+7;
   int func(int length, int one, int zero, vector<int>& dp){
    if(length==0) return 1;
    if(length<0) return 0;

    if(dp[length]!=-1){
        return dp[length];
    }

    int takeOne=func(length-one, one, zero, dp);
    int takeZero=func(length-zero, one , zero, dp);

    return dp[length]=(takeOne+takeZero)%mod;

   }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans=0; 
        vector<int> dp(high+1,-1); 
        for(int i=low;i<=high;i++){
            ans=((ans%mod)+func(i,one,zero,dp))%mod;
        }
        return ans;
    }
};