class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int mid;
        int s=0;
        int e=nums.size()-1;

        while(s<e){
            mid=s+(e-s)/2;
            if(nums[mid]<=nums[mid+1]){
                s=mid+1;
            }
            else{
                e=mid;
            }

        }
        return e;
        
    }
};