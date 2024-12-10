class Solution {
public:

    void func(int node, vector<vector<int>>& isConnected, vector<int>& vis){
        vis[node]=1;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i] and !vis[i]){
                func(i, isConnected, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        int cnt=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                func(i,isConnected,vis);
                cnt++;
            }
        }

        return cnt;
    }
};