class Solution {
public:
  void func(vector<int>& nums, int ind, vector<vector<int>>& ans, vector<int>& res ){

    if(ind>=nums.size()){
        ans.push_back(res) ;
        return;

    } 

    // include
    res.push_back(nums[ind]);
    func(nums, ind+1, ans,res);
    res.pop_back();

    //exclude 
    func(nums, ind+1, ans, res);
    
  }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>res;
        func(nums, 0, ans,res);
        return ans;
        
    }
};