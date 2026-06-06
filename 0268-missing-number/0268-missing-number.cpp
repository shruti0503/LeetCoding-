class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n=nums.size();
        // int expectedSum=n*(n+1)/2;
        // int acutalSum=accumulate(nums.begin(), nums.end(),0);
        // return expectedSum-acutalSum;
           int ans = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            ans ^= i;
            ans ^= nums[i];
        }

        return ans;
        
    }
};