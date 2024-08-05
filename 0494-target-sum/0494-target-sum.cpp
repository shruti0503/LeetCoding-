class Solution {
public:
   int func(vector<int>& nums, int sum , int ind, int target, vector<vector<int>>& dp, int offset){
    // we need to use all the numbers so this base case will not work
    // if(sum==target){
    //     return 1;
    // }
    // if(sum<0) return 0;
    if (ind == nums.size()) {
            return sum == target ? 1 : 0;
    }
    //The dp array is indexed by sum, but sums can be negative, and the size of the dp array does not accommodate negative values. 
    //This will result in incorrect indexing and out-of-bounds errors.
    //The sum of elements in nums can be positive or negative. 
    //The range of possible sums should be considered, and an appropriate offset must be added to handle negative indices.
   if (dp[ind][sum + offset] != -1) return dp[ind][sum + offset];
  
   
     int add=func(nums, sum+nums[ind], ind+1, target,dp, offset);
    int  sub=func(nums, sum-nums[ind], ind+1, target,dp, offset);
   
    
    return dp[ind][sum+offset]=add+sub;
   }

  int tab(vector<int>& nums, int target) {
    int totalSum = 0;
    for (int num : nums) {
        totalSum += abs(num);
    }
    int offset = totalSum;

    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * totalSum + 1, 0));
    
    // Base case: There's one way to reach sum 0 with 0 elements.
    dp[n][offset] = 1;

    for (int ind = n - 1; ind >= 0; --ind) {
        for (int sum = -totalSum; sum <= totalSum; ++sum) {
            int currIndex = sum + offset;
            if (currIndex - nums[ind] >= 0) {
                dp[ind][currIndex] += dp[ind + 1][currIndex - nums[ind]];
            }
            if (currIndex + nums[ind] <= 2 * totalSum) {
                dp[ind][currIndex] += dp[ind + 1][currIndex + nums[ind]];
            }
        }
    }

    return (target + offset >= 0 && target + offset <= 2 * totalSum) ? dp[0][target + offset] : 0;
}

    int findTargetSumWays(vector<int>& nums, int target) {
       
        int totalSum=0;
        for(int num:nums) {
            totalSum+=abs(num);
        }
         int offset = totalSum;

        vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, -1));

        return tab(nums,target);
       // return func(nums, 0, 0, target, dp, offset);
        //The totalSum is the sum of the absolute values of all elements in nums.
        //For example, if nums = [1, 2, 3], then totalSum = 1 + 2 + 3 = 6.
        
    }
};