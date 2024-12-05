class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i,j=0;
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt++;
            }
            if(cnt>k){
                while(nums[j]!=0){
                    j++;
                }
                j++;
                cnt--;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
        
    }
};