class Solution {
public:
  int func(int ind, vector<int>& nums, vector<int>& dp){

     if(ind>nums.size()-1) return 0;
     if(dp[ind]!=-1) return dp[ind];

     int take=nums[ind]+func(ind+2, nums, dp);
     int notTake=func(ind+1, nums,dp);

      dp[ind]=max(take, notTake);

      return dp[ind]; 

  }

 int tab(vector<int>& nums){
    int n=nums.size();
    if (n == 0) return 0;
    vector<int>dp(n+1, 0);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        int take;
        if(i+2<=n){
              take=nums[i]+dp[i+2];
        }
        else{
            take=nums[i];
        }
       
        int notTake=dp[i+1];
        dp[i]=max(take, notTake);
    }

    return dp[0];

 }
   
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        //return func( 0,  nums,  dp);
        return tab(nums);

        
    }
};