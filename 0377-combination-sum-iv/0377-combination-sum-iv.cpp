class Solution {
public:
    int func(vector<int>& nums, int target, vector<int>& dp) {
        // Base case: if target becomes 0, we've found a valid combination
        if (target == 0) return 1;
        // If target is negative, no valid combination
        if (target < 0) return 0;

        // Return already computed result for this target
        if (dp[target] != -1) return dp[target];

        int count = 0;
        // Try each number in nums to see if we can build a combination
        for (int i = 0; i < nums.size(); i++) {
            count += func(nums, target - nums[i], dp);
        }

        return dp[target] = count;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return func(nums, target, dp);
    }
};
