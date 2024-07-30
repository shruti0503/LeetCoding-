class Solution {
public:
    // bool check(int i, int j, string str) {
    //     while (i < j) {
    //         if (str[i] != str[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }

    bool isPali(int i, int j, string& s, vector<vector<int>>& dp){
        // base case
        if(i>=j) return true; // single char or empty string
        if(dp[i][j]!=-1) return dp[i][j]; //return cached string
        if(s[i]==s[j]){ //check if characters at i and j are the same and the substring s[i+1:j-1] is pali
                    dp[i][j]=isPali(i+1, j-1, s,dp);
        }
        else{
            dp[i][j]=false;
        }
        return dp[i][j];
    }

    string tab(string s) {
        int n = s.length();
        if (n == 0) return "";  // Edge case: empty string

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;  // Starting index of the longest palindromic substring
        int maxLength = 1;  // Length of the longest palindromic substring

        // Every single character is a palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check for palindromes of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check for palindromes of length 3 and more
        for (int len = 3; len <= n; len++) {  // len is the length of the substring
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;  // Ending index of the substring
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (len > maxLength) {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }

    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
         vector<vector<int>> dp(n, vector<int>(n, -1));  // Initialize memoization table
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // if (check(i, j, s)) {
                //     int len = j - i + 1;
                //     if (len > ans.size()) {
                //         ans = s.substr(i, len);
                //     }
                // }

                if(isPali(i,j,s, dp)){
                    int len=j-i+1;
                    if(len>ans.size()){
                        ans=s.substr(i,len);
                    }
                }
            }
        }



         return tab(s);
    }
};
