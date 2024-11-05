class Solution {
public:
  int func(int ind, vector<int>& nums, vector<int>& dp){

     if(ind>nums.size()-1) return 0;
     if(dp[ind]!=-1) return dp[ind];

     int take=nums[ind]+func(ind+2, nums, dp);
     int notTake=func(ind+1, nums,dp);

      dp[ind]=max(take, notTake);

      return dp[ind]; 

  }
   
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return func( 0,  nums,  dp);

        
    }
};