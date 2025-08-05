class Solution {
public:
    int func(vector<int>& nums, int ind, int ans, vector<int>& dp){
        if(ind>nums.size() || ind==nums.size())return 0;


        if(dp[ind]!=-1) return dp[ind];

        int take=nums[ind]+func(nums, ind+2, ans, dp);
        int notTake=func(nums, ind+1, ans, dp);
        dp[ind]=max(take, notTake);

        return dp[ind];

    }
    int rob(vector<int>& nums) {
        // 1 , 2 ,3 ,1 
        // pick do not pick
        vector<int>dp(nums.size()+1, -1);
        return func(nums, 0, 0, dp);

    }
};