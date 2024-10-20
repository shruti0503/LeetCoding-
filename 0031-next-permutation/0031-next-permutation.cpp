class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int n=nums.size();
    int breakInd=-1;
    for(int i=0;i<n-1;i++){
        if(nums[i]<nums[i+1]){
            breakInd=i;
        }
    }

    // if no such breakpoint exits
    if(breakInd==-1){
        reverse(nums.begin(), nums.end());
        return;
    }

    // finf the smallest number to the right of the  breaking poiny
    for(int i=n-1;i>breakInd;i--){
        if(nums[i]>nums[breakInd]){
            swap(nums[i], nums[breakInd]);
            break;
        }
    }

    // reverse the lemnts to the break ppint
    reverse(nums.begin()+breakInd+1,nums.end());
    }
};