class Solution {
public:
  int majorityElement(vector<int>& nums) {
        int cnt=0;
        int ele=nums[0];
        
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cnt=1;
                ele=nums[i];
                
            }
            else if(ele==nums[i]) cnt++;
            else cnt--;
        }
       
        return ele;
    }
};