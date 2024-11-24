class Solution {
public:
  int func(vector<int>& prices, int ind, bool buy, int n,  vector<vector<int>>&dp){
   if(ind==prices.size()) return 0;
    int maxProfit=0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy==false){
        // buy it 
        int buy=-prices[ind]+func(prices,ind+1,true,n, dp);
        // skip it
        int skip=func(prices,ind+1, false,n, dp);
        maxProfit=max(buy, skip);
    }
    else{
        int sell= prices[ind]+func(prices,ind+1, false,n,  dp);
        int skip = func(prices,ind+1, true, n, dp);
        maxProfit=max(sell, skip);
    }
    return dp[ind][buy]=maxProfit;
  }
    int maxProfit(vector<int>& prices) {
        // 7 , 1 , 5 , 3 , 6 , 4
        // buy , sell
        // 7 , sell
        // index -> 2 caes
        // 1. buy=true ,
           // sell stock

        //2 , buy =false ,
           // buy the stock 

        // base case :  buy is still false , return 
        // try to sell 

        bool buy=false;
        int ind=0;
        int profit=INT_MIN;
        int n=prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return func(prices, ind, buy,n,dp);

        
    }
};