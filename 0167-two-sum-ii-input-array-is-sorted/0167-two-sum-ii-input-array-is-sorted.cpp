class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        // vector<int>res;
        // constant space chaiye
        while(s<e){
            int sum=nums[s]+nums[e];
          if((sum)==target){
               return {s+1,e+1};
               break;
          }
          else if(sum>target){
              e--;
          }
          else if(sum<target){
              s++;
          }
      } 
      return {-1,-1};       
    }
};