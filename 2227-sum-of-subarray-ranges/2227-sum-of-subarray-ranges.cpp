class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
         long long ans=0;
        for(int si=0;si<nums.size();si++){//si=starting index
           int  smin=INT_MAX;
           int  smax=INT_MIN;
            for(int ei=si;ei<nums.size();ei++){ //ei=ending index
                smin=min(smin,nums[ei]);
                smax=max(smax,nums[ei]);
                ans+=(smax-smin);
                
            }

        }
        return ans;
        
        
    }
};