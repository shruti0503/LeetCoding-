class Solution {
public:
    int minCoins(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0; // base case: no coins needed for amount 0
        if (amount < 0) return INT_MAX; // invalid case: negative amount

        if (dp[amount] != -1) return dp[amount]; // return cached result if already computed

        int mini = INT_MAX;
        for (int coin : coins) {
            int res = minCoins(coins, amount - coin, dp);
            if (res != INT_MAX) {
                mini = min(mini, 1 + res);
            }
        }

        dp[amount] = mini;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1); // memoization array, indexed by amount
        int result = minCoins(coins, amount, dp);
        return result == INT_MAX ? -1 : result; // if result is INT_MAX, return -1 indicating no solution
    }
};
