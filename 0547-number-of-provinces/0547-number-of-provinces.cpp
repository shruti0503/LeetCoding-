class Solution {
public:
  void func(int node,vector<vector<int>>&isConnected, vector<int>& vis ){
     vis[node]=1;
     // travesers ein the adj c list
     for(int i=0;i<isConnected.size();i++){
        // check if edge exists and is not  marked as vsiisted
        if(isConnected[node][i] and !vis[i]){
            func(i, isConnected, vis);
        }
     }
  }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected.size();
        vector<int>vis(n,0);
        int cnt=0;
       //  dfs on  each and every node

        for(int i=0;i<isConnected.size();i++){
            if(vis[i]!=1){
                func(i, isConnected, vis);
                cnt++;
            }
        }

        return cnt;
        
    }
};