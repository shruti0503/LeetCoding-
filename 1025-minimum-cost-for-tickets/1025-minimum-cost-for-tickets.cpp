class Solution {
public:
//start traversing from back and look for all three options i.e all the costs and store the minimum cost in dp array
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+31,0);
        for(int i=n-1;i>=0;i--){
            int nextday=0;
            nextday=lower_bound(days.begin(),days.end(),days[i]+1)-days.begin();
            int op1=costs[0]+dp[nextday];
             nextday=lower_bound(days.begin(),days.end(),days[i]+7)-days.begin();
             int op2=costs[1]+dp[nextday];
              nextday=lower_bound(days.begin(),days.end(),days[i]+30)-days.begin();
              int op3=costs[2]+dp[nextday];
              dp[i]=min(op1,min(op2,op3));

        }
        return dp[0];
        
    }
};