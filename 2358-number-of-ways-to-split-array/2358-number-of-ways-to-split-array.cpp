class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
    long long totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    long long prefixSum = 0; 
    int count = 0;          

   
    for (int i = 0; i < n - 1; i++) {
        prefixSum += nums[i];
        long long rightSum = totalSum - prefixSum;
        if (prefixSum >= rightSum) {
            count++;
        }
    }

    return count;
    }
};