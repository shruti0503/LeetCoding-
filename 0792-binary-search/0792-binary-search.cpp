class Solution {
public:
    int search(vector<int>& nums, int k) {
         int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==k){
                return mid;
            }
            else if(nums[mid]<k){
                s=mid+1;
                
            }
            else{
                e=mid-1;
            }
            
        }
        return -1;
        
        
    }
};