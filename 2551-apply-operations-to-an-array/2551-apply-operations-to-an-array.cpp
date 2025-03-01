class Solution {

public:

    vector<int> applyOperations(vector<int>& nums) {


        // if nums[i]===nums[i+1] multiply  nums[i] by 2 , nums[i+1]=0
        //  else continue
        // after shift all the zeros to the end 
        // 1 2 2 1 1 0
        // 1 4 0  2 0 0
        // 1 4 2 0 0 0

        // 1 4 0 
        // last zero =2
        // 1 4 2 0 0 0


       int lastNonzero=0;
        
       int i=0;
       while(i<=nums.size()-1){
        if(i < nums.size() - 1 and nums[i]==nums[i+1]){
            nums[i]*=2;
            nums[i+1]=0;
        }
        if(nums[i]!=0){
            swap(nums[i], nums[lastNonzero]);
            lastNonzero++;
        }
        i++;
       }

       return nums;

        
    }
};