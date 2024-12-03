class Solution {
public:

   int memo(string s, string t, int i , int j, vector<vector<int>>& dp){
     if(j==t.size()) return 1; // full matched
     if(i==s.size()) return 0; // exhausted s
    if (dp[i][j] != -1) return dp[i][j]; 

     if(s[i]==t[j]){
        int take = memo(s, t, i+1, j+1, dp);
        int notTake=memo(s, t, i+1, j, dp);
        dp[i][j]= take+notTake;  
     }
     else{
         dp[i][j]= memo(s, t, i+1, j, dp);  
     }

     return dp[i][j];

   }
   const int MOD = 1e9 + 7;

   int tab(string s, string t){
        int n = s.size();
    int m = t.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0)); // Use long long

    // Base case: If `t` is empty, there's exactly 1 way
    for (int i = 0; i <= n; i++) {
        dp[i][m] = 1;
    }


    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s[i] == t[j]) {
                long long take = dp[i + 1][j + 1];    // If we take the character
                long long notTake = dp[i + 1][j];    // If we skip the character
                 dp[i][j] = (take + notTake) % MOD;
            } else {
                dp[i][j] = dp[i + 1][j]; // Skip the character
            }
        }
    }

    return dp[0][0]; // Final answer

   }

   int spaceOpt(string s, string t){
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        vector<int>next(m+1,0);
        

        for(int i=0;i<=n;i++){
             dp[i][m]=1;
        }

        for(int i=n-1 ;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i]==t[j]){
                    int take=dp[i+1][j+1];
                    int notTake=dp[i+1][j];
                    dp[i][j]=notTake+take;
                }
                else{
                    dp[i][j]=dp[i+1][j];
                }
            }
        }

        return dp[0][0];



   }

    int numDistinct(string s, string t) {

        // a subsequence is formned -> 
        // if match -> use it / ignnore the char move the s pointer

        // if char do nmot match -> skip it
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        //return  memo(s, t, 0,0, dp);
        return tab(s, t);
        
    }
};