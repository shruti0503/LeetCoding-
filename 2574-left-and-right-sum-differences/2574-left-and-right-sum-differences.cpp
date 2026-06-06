class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum;
        vector<int> rightSum;
        vector<int> ans;
        int left_sum=0;
        int right_sum=0;
        for(int i=0;i<nums.size();i++){
            leftSum.push_back(left_sum);
            rightSum.push_back(right_sum);
            left_sum+=nums[i];
            right_sum+=nums[nums.size()-1-i];
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(abs(leftSum[i]-rightSum[nums.size()-1-i]));
        }
        return ans;
        
    }
};