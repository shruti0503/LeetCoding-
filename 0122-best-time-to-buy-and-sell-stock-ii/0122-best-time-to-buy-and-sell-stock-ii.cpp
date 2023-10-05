class Solution {
public:
    int func(int ind, vector<int>& prices, bool flag,vector<vector<int>>& dp) {
        if (ind == prices.size()) return 0;

        int maxprofit = 0;
        if(dp[ind][flag]!=-1) return dp[ind][flag];

        if (flag == false) {
            // Buy or skip
            int buy = -prices[ind] + func(ind + 1, prices, true,dp);
            int skip = func(ind + 1, prices, false,dp);
            maxprofit = max(buy, skip);
        }
        else {
            // Sell or skip
            int sell = prices[ind] + func(ind + 1, prices, false,dp);
            int skip = func(ind + 1, prices, true,dp);
            maxprofit = max(sell, skip);
        }
        return dp[ind][flag]=maxprofit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,-1));

        return func(0, prices, false,dp); // Start with flag=false (buying state)
    }
};
