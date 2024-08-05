class Solution {
public:
    int rec(int amount, int ind, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) {
            return 1;
        }
        if (amount < 0 || ind >= coins.size()) {
            return 0;
        }
        if (dp[ind][amount] != -1) {
            return dp[ind][amount];
        }

        // Include the current coin and move to the next index
        int includeCurrent = rec(amount - coins[ind], ind, coins, dp);

        // Exclude the current coin and move to the next index
        int excludeCurrent = rec(amount, ind + 1, coins, dp);

        return dp[ind][amount]=includeCurrent+ excludeCurrent;
    }

    int change(int amount, vector<int>& coins) {
        int n= coins.size();
         vector<vector < int>> dp(n + 1, vector<int> (amount + 1, -1));
        return rec(amount, 0, coins, dp);
    }
};
