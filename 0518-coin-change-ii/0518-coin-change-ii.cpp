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
        // take 
         int take =func(amount-coins[ind], coins, ind, ans,dp);

         // not take
         int notTake=func(amount, coins, ind+1, ans,dp);
         return dp[ind][amount]= take+notTake;
   }

   int tab(int money,vector<int>& coins){
    int n=coins.size();
     vector<vector<int>> dp(n+1, vector<int>(money+1, 0));
      // Base case: If amount is 0, there's one way to make the amount (use no coins)
       for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

     for(int ind=n-1;ind>=0;ind--){
        for(int amount=0;amount<=money;amount++){  
        int take=0; // [amount-coins[ind]]= can result in negative index -> can give runtime error
        if(amount>=coins[ind]){
            
             take = dp[ind][amount - coins[ind]];
        } 

         int notTake=dp[ind+1][amount];
          dp[ind][amount]=take+notTake;

        }
       
     }

    return dp[0][money];
   }

   int tab2(int money, vector<int>& coins){

    int n=coins.size();
    vector<vector<int>> dp(n+1, vector<int>(money+1,0));
        //base case
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
            
        }
        for(int ind=n-1;ind>=0;ind--){
            for(int amount=money;amount>=0;--amount){
                int take=0;
                if(amount>=coins[ind]){
                    take=dp[ind][amount-coins[ind]];
                }
                int notTake=dp[ind+1][amount];
                dp[ind][amount]=take+notTake;
            }
        }

        return dp[0][money];
   }
   int spaceOpt(int money, vector<int>& coins){

    int n=coins.size();
    // vector<vector<int>> dp(n+1, vector<int>(money+1, 0));
     vector<int> curr (money+1,0);
     vector<int>next(money+1,0);
      // Base case: If amount is 0, there's one way to make the amount (use no coins)
    //    for (int i = 0; i <= n; ++i) {
    //     [i][0] = 1;
    // }
    curr[0]=1;
    next[0]=1;

     for(int ind=n-1;ind>=0;ind--){
        for(int amount=0;amount<=money;amount++){  
        int take=0; // [amount-coins[ind]]= can result in negative index -> can give runtime error
        if(amount>=coins[ind]){
             take = curr[amount - coins[ind]];
        } 

         int notTake=next[amount];
          curr[amount]=take+notTake;

        }
       next=curr; // Move current row to next row for next iteration
     }

    return curr[money];

   }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        //If you have an amount of 5, you need to consider indices from 0 to 5, which totals 6 indices. Thus, the array needs to be of size amount + 1.
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
       // return func(amount, coins, 0, 0,dp);
        // return tab(amount, coins);
        // return tab2(amount,coins);
        return spaceOpt(amount, coins);
        
    }
};