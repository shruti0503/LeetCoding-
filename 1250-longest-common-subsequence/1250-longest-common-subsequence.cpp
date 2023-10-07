class Solution {
public:
   int func(int ind1, int ind2,string s1, string s2,vector<vector<int>>& dp){
       if(ind1==s1.size()) return 0;
       if(ind2==s2.size()) return 0;

       // take 
       int maxlen=INT_MIN;
       if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
       if(s1[ind1]==s2[ind2]){
           int take=1+func(ind1+1, ind2+1, s1, s2,dp);
           maxlen=max(take,maxlen);
       }
       else{
          int nottake1= func(ind1+1, ind2, s1, s2,dp);
          int nottake2= func(ind1, ind2+1, s1, s2,dp);
           maxlen=max(nottake1,nottake2);
       }
       return dp[ind1][ind2]=maxlen;
   }
   int tab(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int ind1 = n - 1; ind1 >= 0; ind1--) {
        for (int ind2 = m - 1; ind2 >= 0; ind2--) {
            if (s1[ind1] == s2[ind2]) {
                dp[ind1][ind2] = 1 + dp[ind1 + 1][ind2 + 1];
            } else {
                dp[ind1][ind2] = max(dp[ind1 + 1][ind2], dp[ind1][ind2 + 1]);
            }
        }
    }

    return dp[0][0];
}

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();

        vector<vector<int>>dp(n, vector<int>(m,-1));
        //return func(0,0, text1, text2,dp);
        return tab(text1, text2);
    }
};