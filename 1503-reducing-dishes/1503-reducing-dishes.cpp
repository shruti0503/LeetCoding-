class Solution {
public:
// Maximizing Satisfaction: The goal is to maximize the sum of satisfactions, 
// calculated as satisfaction[i] * (time + 1) for each dish i. 
// If you choose to serve a dish with high satisfaction earlier,
//  the multiplier (time + 1) will be smaller than if you served it later.
//   By sorting the array in ascending order, you ensure that lower satisfaction values 
//   are handled first,
//  leaving space for larger values to have a bigger impact.
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
    int tab(vector<int>& sat){
        int n=sat.size();
       sort(sat.begin(), sat.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0)); // yhi ke yhi intialise kr do

        for(int ind=n-1;ind>=0;ind--){
            for(int time=ind; time>=0;time--){
                int include=(sat[ind]*(time+1))+dp[ind+1][time+1];
                int exclude=dp[ind+1][time];
                dp[ind][time]=max(include, exclude);
                
            }
        }

        return dp[0][0];
       

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        //return func(satisfaction, 1, 0 , dp);
        return tab(satisfaction);
        
    }
};