class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
//         if(nums.size()==0){
//             return 0;
//             }
//         sort(nums.begin(),nums.end());
//         int currlen=1;
//         int maxlen=1;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i+1]!=nums[i-1]+1){
//                 if(nums[i]==nums[i-1]+1){
//                 currlen++;
//                 // maxlen=max(currlen,maxlen);
//                 }

//             }
//             else{ 
                
//                 maxlen=max(currlen,maxlen);
//                 currlen=1;
                

//             }
//         }
//         return max(maxlen,currlen);
        
        int ans=1;
        if(nums.size()==0)
            return 0;
        
        sort(nums.begin(),nums.end());
        int curr;
        int j=1;
        curr=1;
        while(j<nums.size())
        {
            if(nums[j]-nums[j-1]==0)
            {
                j++;
                continue;
            }
            else if(nums[j]-nums[j-1]==1)
            {
                
                curr++;
                ans=max(ans,curr);
            }
            else
            {
                curr=1;
            }
            j++;
        }
        
        return ans;
    }
};