class Solution {
public:
   int func(vector<int>& sat, int time , int ind, vector<vector<int>>& dp){
        if(ind>=sat.size()){
            return 0;
        }
        if(dp[ind][time]!=-1) return dp[ind][time];
        int include= (sat[ind]* (time) )+func(sat, time+1, ind+1, dp);
         int exclude= func(sat, time, ind+1, dp);

         dp[ind][time]=max(include, exclude);
         return dp[ind][time];

         

   }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return func(satisfaction, 1, 0 , dp);
        
    }
};