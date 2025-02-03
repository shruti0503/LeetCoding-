class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // test cases
        // 1 4 3 3 2
        // 321
        //1971
        int i=0;
        int j=1;
        int n=nums.size();
        int len=1;
        int inc=1;
        int dec=1;
        int ans=0;
        while(j<n){

             if(nums[j]>nums[i]){
               
                inc++;
                len=max(len,max(inc, dec));
                dec=1;
                
             }
             else if(nums[j]<nums[i]){
                dec++;
                len=max(len,max(inc, dec));
                inc=1;
                 
             }
             else{
                inc=1;
                dec=1;
                 len=max(len,max(inc, dec));
             }
            i++;
            j++;
            
            
        }
        return len;
        
    }
};