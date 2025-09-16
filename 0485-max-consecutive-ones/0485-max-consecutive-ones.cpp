class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int ans=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
                ans=max(ans,cnt);
            }
            else cnt=0;
        }
        return ans==INT_MIN?0:ans;
        
    }
};