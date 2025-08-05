class Solution {
public:
    int cnt(int right, int down, int m, int n, vector<vector<int>>& dp) {
        if (right > n - 1 || down > m - 1) {
            return 0;
        }
        if (right == n - 1 && down == m - 1) {
            return 1;
        }

        if (dp[down][right] != -1) {
            return dp[down][right];
        }

        return dp[down][right] = cnt(right + 1, down, m, n, dp) + cnt(right, down + 1, m, n, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return cnt(0, 0, m, n, dp);
    }
};
