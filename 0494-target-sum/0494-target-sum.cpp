class Solution {
public:
   int func(vector<int>& nums, int sum , int ind, int target){
    // we need to use all the numbers so this base case will not work
    // if(sum==target){
    //     return 1;
    // }
    // if(sum<0) return 0;
    if (ind == nums.size()) {
            return sum == target ? 1 : 0;
    }
  
   
     int add=func(nums, sum+nums[ind], ind+1, target);
    int  sub=func(nums, sum-nums[ind], ind+1, target);
   
    
    return add+sub;
   }
    int findTargetSumWays(vector<int>& nums, int target) {
        return func(nums, 0,0,target);
        
    }
};