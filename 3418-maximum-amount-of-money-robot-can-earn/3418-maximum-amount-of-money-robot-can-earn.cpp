class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int k, vector<vector<int>>& coins) {
        if (i >= m || j >= n) return INT_MIN;

        // base case
        if (i == m-1 && j == n-1) {
            if (coins[i][j] >= 0) return coins[i][j];
            else {
                if (k > 0) return 0;
                else return coins[i][j];
            }
        }

        if (dp[i][j][k] != INT_MIN) return dp[i][j][k];

        int val = coins[i][j];

        int down = solve(i+1, j, k, coins);
        int right = solve(i, j+1, k, coins);

        int bestNext = max(down, right);

        // option 1: take value
        int take = INT_MIN;
        if (bestNext != INT_MIN)
            take = val + bestNext;

        // option 2: neutralize
        int neutralize = INT_MIN;
        if (val < 0 && k > 0) {
            int down2 = solve(i+1, j, k-1, coins);
            int right2 = solve(i, j+1, k-1, coins);
            neutralize = max(down2, right2);
        }

        return dp[i][j][k] = max(take, neutralize);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        dp = vector(m, vector(n, vector<int>(3, INT_MIN)));

        return solve(0, 0, 2, coins);
    }
};