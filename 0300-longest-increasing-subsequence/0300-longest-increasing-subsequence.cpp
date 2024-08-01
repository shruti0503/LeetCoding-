class Solution {
public:
    int func(vector<int>& nums, int ind, int prev, int n, vector<vector<int>>& dp) {
        // Base case: If we've considered all elements
        if (ind == n) return 0;
        
        // Check if the result is already computed
        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
        
        // Not taking the current element
        int notTake = func(nums, ind + 1, prev, n, dp);
        
        // Taking the current element (if it forms an increasing subsequence)
        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + func(nums, ind + 1, ind, n, dp);
        }
        
        // Store the result in dp array
        return dp[ind][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return func(nums, 0, -1, n, dp);
    }
};
