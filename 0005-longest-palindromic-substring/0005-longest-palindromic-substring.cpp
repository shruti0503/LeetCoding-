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



         return ans;
    }
};
