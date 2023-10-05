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

    int tab(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; --ind) {
        for (int state = 0; state <= 1; ++state) {
            if (state == 0) {
                int buy = -prices[ind] + dp[ind + 1][1];
                int skip = dp[ind + 1][0];
                dp[ind][0] = max(buy, skip);
            } else {
                int sell = prices[ind] + dp[ind + 1][0];
                int skip = dp[ind + 1][1];
                dp[ind][1] = max(sell, skip);
            }
        }
    }

    return dp[0][0]; // Result for the original problem, starting in the buying state.
}

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,-1));

       // return func(0, prices, false,dp); // Start with flag=false (buying state)
       return tab(prices);
    }
};
