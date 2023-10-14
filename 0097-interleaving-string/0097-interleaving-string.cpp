class Solution {
public:
    // Define a memoization table with -1 to indicate uncomputed values
    vector<vector<int>> memo;

    bool func(int i, int j, int n, int m, string& s1, string& s2, string& s3) {
        if (i == n && j == m) {
            return true; // Base case: both s1 and s2 have been fully interleaved
        }

        if (memo[i][j] != -1) {
            return memo[i][j]; // Return the precomputed result if available
        }

        bool result = false;
        // Check if the current character of s1 matches s3 and continue with s1
        if (i < n && s1[i] == s3[i + j] && func(i + 1, j, n, m, s1, s2, s3)) {
            result = true;
        }

        // Check if the current character of s2 matches s3 and continue with s2
        if (!result && j < m && s2[j] == s3[i + j] && func(i, j + 1, n, m, s1, s2, s3)) {
            result = true;
        }

        memo[i][j] = result; // Store the result in the memoization table
        return result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if (n + m != s3.size()) {
            return false; // Length mismatch, s3 cannot be formed by interleaving s1 and s2
        }

        // Initialize the memoization table with -1 (uncomputed) values
        memo = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));

        return func(0, 0, n, m, s1, s2, s3);
    }
};