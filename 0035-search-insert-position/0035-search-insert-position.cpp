class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = -1;
        int start = 0;
        int end = nums.size()-1;
       
        while(start<=end){
            int mid = start+(end-start)/2;
            cout<<"mid is "<<mid <<endl;
            
            if(nums[mid]==target){
                ans = mid;
                return mid;
            }else if(nums[mid]<target){
                start = mid+1;
                ans = start;
            }else{
                end =mid-1;
            }
        }
        
        if(ans==-1){
            return 0;
        }
     
        return ans;
    }
};