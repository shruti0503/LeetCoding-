class Solution {
public:
    bool func(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        
        if (i < 0 && j < 0) return true;
        if (i>=0 and j<0) return false;
        if (i < 0 and j>=0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        
        // If match
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = func(i - 1, j - 1, s, p, dp);
        } else if (p[j] == '*') {
            // Handle p[j] == '*' when s[i] == p[j]
            return dp[i][j] = (func(i - 1, j, s, p, dp) || func(i, j - 1, s, p, dp));
        } else {
            return dp[i][j] = false;
        }
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return func(n - 1, m - 1, s, p, dp);
    }
};
