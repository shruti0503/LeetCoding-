class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxSide = 0;

        // Initialize first row and first column
        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0] - '0';
            maxSide = max(maxSide, dp[i][0]);
        }
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j] - '0';
            maxSide = max(maxSide, dp[0][j]);
        }

        // Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '1') {
                    int top = dp[i-1][j];
                    int left = dp[i][j-1];
                    int diag = dp[i-1][j-1];
                    dp[i][j] = min({top, left, diag}) + 1;
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        // Return the area of the largest square
        return maxSide * maxSide;
    }
};
