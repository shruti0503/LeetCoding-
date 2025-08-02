class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;

        while(i <= j){
            if(nums[i] + nums[j] > target)
                j--;
            else{
                count = (count + getPowerOfTwo(j-i, mod)) % mod;
                i++;
            }
        }
        return count;
    }

    int getPowerOfTwo(int n, int mod) {
        int res = 1;
        long base = 2;
        while(n > 0) {
            if(n % 2 == 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            n /= 2;
        }
        return res;
    }
};
