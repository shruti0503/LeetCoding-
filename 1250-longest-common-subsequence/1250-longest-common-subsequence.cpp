class Solution {
public:
  int func(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp){
    if(ind1==s1.size() || ind2==s2.size()) return 0;

    // take 
    int maxlen=INT_MIN;
     if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(s1[ind1]==s2[ind2]){
        int take=1+func(ind1+1, ind2+1, s1, s2, dp);
        maxlen=max(take, maxlen);
    }
    else{ // in not take there will be w cases , move ind1 or ind2
        int nottake1=func(ind1+1, ind2, s1, s2, dp);
        int nottake2= func(ind1, ind2+1, s1, s2, dp);

        maxlen=max(nottake1, nottake2);
    }

    return dp[ind1][ind2]=maxlen;

    
  }

  int tab(string s1, string s2){
    int n=s1.size();
    int m=s2.size();
    int ind1=0;
    int ind2=0;
    //The initial values of dp should be 0, not -1, since dp[i][0] and dp[0][i] represent the LCS of an empty string with any prefix of the other string, which is always 0.
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            // s1[ind1-1] and s2[ind2-1] because the dp table is 1-indexed, but the strings are 0-indexed.
            if(s1[ind1-1]==s2[ind2-1]){
                dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
            }
            else{
                dp[ind1][ind2]=max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
    }

    return dp[n][m];

  }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return tab(text1, text2);
        //return func(0,0,text1, text2, dp);


        
    }
};