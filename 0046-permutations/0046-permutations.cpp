class Solution {
public:

    void func(vector<int> nums, vector<vector<int>>& ans, int ind){
        if(ind>=nums.size()){
            ans.push_back(nums);
        }
        for(int j=ind;j<nums.size();j++){
            swap(nums[ind], nums[j]);
            func(nums, ans, ind+1);
            swap(nums[ind], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int ind=0;
        func(nums, ans, ind);
        return ans;
           
    }
};