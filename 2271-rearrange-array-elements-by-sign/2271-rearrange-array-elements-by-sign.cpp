class Solution {
    
public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int>ans;
//         int n=nums.size();
//         int i=0,j=0;
//         while(i<n && j<n){
//             while(i<n && nums[i]<0){
//                 i++;
//             }
//             while(j<n && nums[j]>0){
//                 j++;
//             }
//             ans.push_back(nums[i]);
//             ans.push_back(nums[j]);

//         }
//         nums=ans;
//         ans.clear();
//         return nums;
    
            
//     }
    vector<int> rearrangeArray(vector<int>& nums)
    {
        vector<int> res;
        for(int i=0,j=0;j<nums.size()&&i<nums.size();i++,j++)
        {
            while(i<nums.size()&&nums[i]<0)
            {
                i++;
            }
            while(j<nums.size()&&nums[j]>0)
            {
                j++;
            }
            res.push_back(nums[i]);
            res.push_back(nums[j]);
        }
        return res;}
};