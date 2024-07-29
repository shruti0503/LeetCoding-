class Solution {
public:
    // Memoization function
    int memo(vector<int>& nums, int ind, vector<int>& dp) {
        int n = nums.size();
        if (ind >= n) return 0; // if ind exceeds the length of nums, return 0

        if (dp[ind] != -1) return dp[ind];

        int inc = nums[ind] + memo(nums, ind + 2, dp);
        int exc = memo(nums, ind + 1, dp);

        return dp[ind] = max(inc, exc); // store the result in dp array
    }

    // Dynamic programming function
    int func(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }

        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<int> dp1(n, -1); // Note: Changed size to n
        vector<int> dp2(n, -1); // Note: Changed size to n
        
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());

        int a1 = memo(nums1, 0, dp1);
        int a2 = memo(nums2, 0, dp2);

        return max(a1, a2);
    }
};
