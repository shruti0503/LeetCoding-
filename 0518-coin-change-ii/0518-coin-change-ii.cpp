class Solution {
public:
   int func(int amount, vector<int>& coins, int ind, int ans,vector<vector<int>>& dp){
        
        if (amount == 0) {
            return 1;
        }
        if (amount < 0 || ind >= coins.size()) {
            return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];

       


    //    for(int i=ind;i<coins.size();i++){
        // take 
         int take =func(amount-coins[ind], coins, ind, ans,dp);

         // not take
         int notTake=func(amount, coins, ind+1, ans,dp);
    //    }

       return dp[ind][amount]= take+notTake;


    

   }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        //If you have an amount of 5, you need to consider indices from 0 to 5, which totals 6 indices. Thus, the array needs to be of size amount + 1.
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return func(amount, coins, 0, 0,dp);
        
    }
};