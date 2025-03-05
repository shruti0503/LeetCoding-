class Solution {
public:
     int func(vector<int>& nums, int ind, int prev , int n , vector<vector<int>>& dp){
        if(ind==n) return 0;
        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
        int notTake=func(nums, ind+1, prev, n, dp);
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev]){
            take=1+func(nums, ind+1, ind, n, dp);

        }
        return dp[ind][prev + 1] =  max(take, notTake);
     }
    int lengthOfLIS(vector<int>& nums) {
        // 10 , 9. 
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return func(nums, 0, -1 , n, dp);
    }
};