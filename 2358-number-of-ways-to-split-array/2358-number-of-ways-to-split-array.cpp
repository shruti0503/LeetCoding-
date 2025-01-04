class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
    long long totalSum = 0; // To hold the total sum of the array
    for (int num : nums) {
        totalSum += num;
    }

    long long prefixSum = 0; // To track the prefix sum
    int count = 0;           // To count the valid splits

    // Iterate through the array to check valid splits
    for (int i = 0; i < n - 1; i++) { // We stop at n-1 because the right part must be non-empty
        prefixSum += nums[i];
        long long rightSum = totalSum - prefixSum;
        if (prefixSum >= rightSum) {
            count++;
        }
    }

    return count;
    }
};