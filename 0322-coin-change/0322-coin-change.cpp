class Solution {
public:

//  int tab( vector<int>& coins, int amount, vector<int>& dp){
//      // create dp array
//      vector<int> dp(amount+1, INT_MAX);
//      // initailse base case
//      dp[0]=0;
//      //now trying to fount out for every amount figure from 1 to x.
//      for(int i=1;i<=x;i++){
//          for(int j=0;j<coins.size();i++){
//              // note that here i is my particular amount 
//              if(i-nums[j]>=0 and dp[i-nums[j]]!=INT_MAX){
//                  dp[i]=min(dp[i], i+dp[i-nums[j]]);
//              }
//          }

//      }
//     // amount hi final amount h 
//      if(dp[amount]==INT_MAX){
//          return -1;
        
//      }
//      return dp[amount]

//  }
    // int func(vector<int>& coins, int amount, vector<int>& dp) {
    //     if (amount == 0) return 0;
    //     if (amount < 0) return INT_MAX;
    //     int mini = INT_MAX;
    //     if (dp[amount] != -1) return dp[amount];

    //     for (int i = 0; i < coins.size(); i++) {
    //         int ans = func(coins, amount - coins[i], dp);
    //         if (ans != INT_MAX) {
    //             mini = min(mini, 1 + ans);
    //         }
    //     }
    //     dp[amount] = mini;
    //     return dp[amount];
    // }

    int coinChange(vector<int>& coins, int amount) {
        // create dp array
     vector<int> dp(amount+1, INT_MAX);
     // initailse base case
     dp[0]=0;
     //now trying to fount out for every amount figure from 1 to x.
     for(int i=1;i<=amount;i++){
         for(int j=0;j<coins.size();j++){
             // note that here i is my particular amount 
             if(i-coins[j]>=0 and dp[i-coins[j]]!=INT_MAX){
                 dp[i]=min(dp[i], 1+dp[i-coins[j]]);
             }
         }

     }
    // amount hi final amount h 
     if(dp[amount]==INT_MAX){
         return -1;
        
     }
     return dp[amount];
    }
};
