class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakInd = -1;
        int n = nums.size();

        // Find the index where the current permutation breaks the increasing order
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                breakInd = i;
            }
        }

        // If no such breakpoint exists, reverse the entire array to get the smallest permutation
        if (breakInd == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the smallest number to the right of breakInd that is greater than nums[breakInd]
        for (int i = n - 1; i > breakInd; i--) {
            if (nums[i] > nums[breakInd]) {
                swap(nums[i], nums[breakInd]);
                break;
            }
        }

        // Reverse the elements to the right of breakInd to get the next permutation
        reverse(nums.begin() + breakInd + 1, nums.end());
    }
};