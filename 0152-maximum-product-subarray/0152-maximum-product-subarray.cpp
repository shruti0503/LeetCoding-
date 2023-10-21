class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1;
        int maxprod=INT_MIN;
        if(nums.size()==1){
            return nums[0];
        }

        for(int i=0;i<nums.size();i++){
            prod*=nums[i];
            maxprod=max(maxprod,prod);
            if(prod==0){
                prod=1;
            }
        }
        prod=1;
         for(int i=nums.size()-1;i>=0;i--){
            prod*=nums[i];
            maxprod=max(maxprod,prod);
            if(prod==0){
                prod=1;
            }
        }
        return maxprod;
        
    }
};