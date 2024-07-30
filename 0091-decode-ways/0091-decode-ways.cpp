class Solution {
public:
    int rec(string& s, int index){
        if(index==s.size()) return 1;
        if(s[index]=='0') return 0;

        int count=0;
        count+=rec(s, index+1);
        if(index+1<s.size() and (s[index]=='1' or (s[index]=='2' and s[index+1]<='6'))){
            count+=rec(s,index+2);
        }
        return count;
    }

    int memo(string& s, int index, vector<int>& dp){
        if(index==s.size()) return 1;
        if(s[index]=='0') return 0;

        int count=0;
        if(dp[index]!=-1) return dp[index];
        count+=memo(s, index+1,dp);
        if(index+1<s.size() and (s[index]=='1' or (s[index]=='2' and s[index+1]<='6'))){
            count+=memo(s,index+2,dp);
        }
        return dp[index]=count;

    }

    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
       // return rec(s,0);
        return memo(s,0,dp);
        
    }
};