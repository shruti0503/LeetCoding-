class Solution {
public:
int func(int ind, vector<int>& prices, bool flag, int limit, vector<vector<vector<int>>>& dp) {
        if(limit==2) return 0;
        if (ind == prices.size()) return 0;
        int maxprofit = 0;
       // if(dp[ind][flag]!=-1) return dp[ind][flag];

       if(dp[ind][flag][limit]!=-1) return dp[ind][flag][limit];

        if (flag == false) {
            // Buy or skip
            int buy = -prices[ind] + func(ind + 1, prices, true,limit,dp);
            int skip = func(ind + 1, prices, false,limit,dp);
            maxprofit = max(buy, skip);
        }
        else {
            // Sell or skip
            int sell = prices[ind] + func(ind + 1, prices, false,limit+1,dp);
            int skip = func(ind + 1, prices, true,limit,dp);
            maxprofit = max(sell, skip);
        }
        return dp[ind][flag][limit]=maxprofit;
    }
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2, vector(3,-1)));
        return func(0, prices,false,0,dp);
        
    }
};