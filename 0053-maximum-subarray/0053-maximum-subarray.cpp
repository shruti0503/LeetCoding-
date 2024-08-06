class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxans=INT_MIN;
        int currSum=0;
         
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            maxans=max(currSum, maxans);
            if(currSum<0){
                currSum=0;

                
            }
            
            

        }
        return maxans;
    }
};