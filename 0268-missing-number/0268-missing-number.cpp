class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;  // Sum of 0 to n
        int actualSum = accumulate(nums.begin(), nums.end(), 0); // Sum of elements in nums
        return expectedSum - actualSum;  // The missing number
    }
};