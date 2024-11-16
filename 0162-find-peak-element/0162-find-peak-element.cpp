class Solution {
public:
    int findPeakElement(vector<int>& nums) {
   // try to visulaise a mountian 
 //             //  -> this is the peak elemnt
 //           //  \\
//           //    \\
// if mid lies inthe left part we need to shift it to the peak 
// therefore if(nums[mid]<=nums[mid+1]) // lies in left => move forward to the peak elemt
// else it lies in right part so simply e=mid ; beacuse mid can also be a peak element
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