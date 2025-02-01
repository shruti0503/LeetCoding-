class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            bool isOdd = (nums[i] % 2 != 0);
            if (i > 0 && (nums[i - 1] % 2 != 0) == isOdd) {
                return false;
            }
            if (i < n - 1 && (nums[i + 1] % 2 != 0) == isOdd) {
                return false;
            }
        }
        
        return true;
    }
};
