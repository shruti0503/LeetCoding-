class Solution {
public:
    int func(int i, int j, string &s, vector<vector<int>>& dp) {
        // Base cases
        if (i > j) return 0;      // No valid subsequence if i > j
        if (i == j) return 1;      // Single character is a palindrome of length 1
        
        // Check if the result for this subproblem is already computed
        if (dp[i][j] != -1) return dp[i][j];
        
        // Recursive case with memoization
        if (s[i] == s[j]) {
            // If characters match, add 2 to the result of the inner substring
            dp[i][j] = 2 + func(i + 1, j - 1, s, dp);
        } else {
            // If characters don't match, consider the maximum length by excluding either side
            dp[i][j] = max(func(i + 1, j, s, dp), func(i, j - 1, s, dp));
        }
        
        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // Initialize the dp array with -1 to indicate uncomputed states
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return func(0, n - 1, s, dp);
    }
};
