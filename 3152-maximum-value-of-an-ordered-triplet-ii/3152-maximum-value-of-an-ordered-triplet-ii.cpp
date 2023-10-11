class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        if (nums.size() == 3) {
            long long ans=(long long)(((long long)nums[0]-(long long)nums[1])*(long long)nums[2]);
            if(ans>=0) return ans;
            else return 0;
           // return ans ? ans>=0 : -1;
        }

        vector<int> max_front(nums.size(), 0);
        long long maxval = LONG_LONG_MIN;
        vector<long long> max_back(nums.size(), 0);

        // Calculate max_front and max_back values
        for (int i = 1; i < nums.size(); i++) {
            max_front[i] = max(maxval, (long long)nums[i - 1]);
            maxval = max(maxval, (long long)nums[i - 1]);
        }

        maxval = LONG_LONG_MIN;
        for (int i = nums.size() - 2; i >= 0; i--) {
            max_back[i] = max(maxval, (long long)nums[i + 1]);
            maxval = max(maxval, (long long)nums[i + 1]);
        }

        // Calculate the maximum value
        maxval = LONG_LONG_MIN;
        for (int i = 1; i < nums.size() - 1; i++) {
            long long a = max_front[i];
            long long c = max_back[i];
            long long ans = ((a - nums[i]) * c);
            maxval = max(maxval, ans);
        }

        // return maxval ? maxval > 0 : -1 ;
        if(maxval>=0) return maxval;
        else 
        return 0;
    }
};
