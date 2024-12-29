class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mpp;
        mpp[0] = 1;        // prefix sum 0 to handle cases when sum == k
        int sum = 0;       
        int cnt = 0;      

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int remaining = sum - k;
            if (mpp.find(remaining) != mpp.end()) {
                cnt += mpp[remaining];
            }

          
            mpp[sum]++;
        }

        return cnt; 
    }
};