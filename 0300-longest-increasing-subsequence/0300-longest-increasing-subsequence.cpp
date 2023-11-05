class Solution {
public:
  int func(vector<int>& nums, int ind, int prev, vector<vector<int>>& dp){
      if(ind == nums.size()){
          return 0;
      }
      if(dp[ind][prev+1] != -1){
          return dp[ind][prev+1];
      }
      int take = 0;
      // If the current ele is greater than prev, then count it in the LIS
      if(prev == -1 || nums[ind] > nums[prev]){
          take = 1 + func(nums, ind + 1, ind, dp);
      }
      // Do not pick the element, keep the previous element
      int nottake = func(nums, ind + 1, prev, dp);
      int ans = max(take, nottake);
      dp[ind][prev+1] = ans; // Store the result in dp
      return ans;
  }

  int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>> dp(n+1, vector<int>(n+1, -1)); // Correct allocation
      return func(nums, 0, -1, dp);
  }
};
