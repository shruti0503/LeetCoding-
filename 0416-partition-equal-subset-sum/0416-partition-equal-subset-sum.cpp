class Solution {
public:
// dp[i][j] represents wheater its possible to acivev a sum j using the first i elemnts of the array
    bool func(vector<int>& nums, int ind, int sum,  vector<vector<int>>& dp) {
        if (sum == 0) {
            return true;
        }

        if (ind >= nums.size()) {
            return false;
        }
        if(sum<0){
            return false;
        }
        if(dp[ind][sum]!= -1){
            return dp[ind][sum];
        }
       
        bool  take = func(nums, ind + 1, sum - nums[ind], dp);  
        
        bool notake = func(nums, ind + 1, sum, dp);  

        return dp[ind][sum] = take || notake;
    }

     bool tab(vector<int>& nums){
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // If the sum is odd, we cannot partition it into two equal subsets
        if (sum % 2 != 0) {
            return false;
        }
        
        int target = sum / 2;
        int n = nums.size();
        
        // Initialize the DP table
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        
        // Base case: sum of 0 is possible with any subset (by not including any elements)
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }
        
        // Fill the DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                // Not take the current element
                dp[i][j] = dp[i - 1][j];
                
                // Take the current element (if it does not exceed the sum)
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        
        // Return the result
        return dp[n][target];

     }

     bool spaceopt(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // If the sum is odd, we cannot partition it into two equal subsets
        if (sum % 2 != 0) {
            return false;
        }
        
        int target = sum / 2;
        int n = nums.size();
        
        // Initialize a single-dimensional DP array
        vector<bool> dp(target + 1, false);
        
        // Base case: sum of 0 is possible with any subset (by not including any elements)
        dp[0] = true;
        
        // Fill the DP array
        for (int i = 0; i < n; ++i) {
            // Iterate backwards to avoid overwriting results within the same iteration
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        
        // Return the result
        return dp[target];
    }


    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }

       vector<vector<int>>dp (nums.size(), vector<int>(sum+1, -1));
       return spaceopt(nums);
    }
};