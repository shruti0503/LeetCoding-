class Solution {
public:int func(int ind, vector<int>& prices, bool flag, int limit, vector<vector<vector<int>>>& dp, int k) {
        if(limit==k) return 0;
        if (ind == prices.size()) return 0;
        int maxprofit = 0;
       // if(dp[ind][flag]!=-1) return dp[ind][flag];

       if(dp[ind][flag][limit]!=-1) return dp[ind][flag][limit];

        if (flag == false) {
            // Buy or skip
            int buy = -prices[ind] + func(ind + 1, prices, true,limit,dp,k);
            int skip = func(ind + 1, prices, false,limit,dp,k);
            maxprofit = max(buy, skip);
        }
        else {
            // Sell or skip
            int sell = prices[ind] + func(ind + 1, prices, false,limit+1,dp,k);
            int skip = func(ind + 1, prices, true,limit,dp,k);
            maxprofit = max(sell, skip);
        }
        return dp[ind][flag][limit]=maxprofit;
    }
    int tab(int k, vector<int>& prices){
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector(k+1,0)));
        int maxProfit=0;
        for(int ind=n-1;ind>=0;--ind){
            for(int flag=0; flag<=1;++flag){
                for(int limit=0;limit<k;++limit){
                    if (flag == 0) {
                        // Buy or skip
                        int buy = -prices[ind] + dp[ind + 1][1][limit];
                        int skip = dp[ind + 1][0][limit];
                        dp[ind][flag][limit] = max(buy, skip);
                    }
                    else {
                        // Sell or skip
                        int sell = prices[ind] + dp[ind + 1][0][limit+1];
                        int skip = dp[ind + 1][1][limit];
                        dp[ind][flag][limit] = max(sell, skip);
                    }
                    
                }
            }
        }

        return  dp[0][0][0];
    

    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2, vector(k+1,-1)));
       // return func(0, prices,false,0,dp,k);
       return tab(k,prices);
    }
};