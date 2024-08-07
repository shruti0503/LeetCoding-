class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump=INT_MIN;
        for(int i=0;i<nums.size();i++){
            // if(nums[i]<)
            maxJump=max(nums[i], maxJump);
            if(i==nums.size()-1){
                return true;
            }
            if(maxJump==0){
                return false;
            }
            maxJump--;
        }

        return false;
    }
};