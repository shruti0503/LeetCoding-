class Solution {
public:
int mod=1e9+7;
int solve(int targetLength,int one,int zero,vector<int> &dp){
    if(targetLength==0) return 1;
    if(targetLength<0) return 0;
    if(dp[targetLength]!=-1) return dp[targetLength];
    long long sum;
    sum=solve(targetLength-one,one,zero,dp)+solve(targetLength-zero,one,zero,dp);
    return dp[targetLength]=sum%mod;
}
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans=0; //storing the sum
        vector<int> dp(high+1,-1); //to store the computations
        for(int i=low;i<=high;i++){
            ans=((ans%mod)+solve(i,one,zero,dp))%mod;
        }
        return ans;
    }
};