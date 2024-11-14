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
    int tab(string s){
       int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: a single character is a palindrome of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Build the dp table for substrings of increasing lengths
        for (int len = 2; len <= n; len++) {       // len is the length of the substring
            for (int i = 0; i <= n - len; i++) {    // i is the starting index of the substring
                int j = i + len - 1;                // j is the ending index of the substring
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        // The answer for the longest palindromic subsequence is in dp[0][n-1]
        return dp[0][n - 1];

    }

     int spaceOpt(string s){
         int n = s.size();
        vector<int> prev(n, 0), curr(n, 0);

        // Loop from end of the string towards the beginning to fill up the DP table
        for (int i = n - 1; i >= 0; i--) {
            curr[i] = 1; // Base case: a single character is a palindrome of length 1
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    curr[j] = prev[j - 1] + 2;
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr; // Move current row to previous for the next outer iteration
        }

        // The result for the entire string is now in prev[n-1]
        return prev[n - 1];

    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // Initialize the dp array with -1 to indicate uncomputed states
        vector<vector<int>> dp(n, vector<int>(n, -1));
        //return func(0, n - 1, s, dp);
        return tab(s);
    }
};
