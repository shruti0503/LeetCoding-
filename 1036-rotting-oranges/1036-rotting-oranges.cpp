class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         queue<pair<pair<int,int>,int>>pq;
        vector<vector<int>> vis(n,vector<int>(m,0));

        int cntFresh=0;
        int time=0;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2  ){
                    pq.push({{i,j},0});
                    vis[i][j]=1;
                    
                }
                if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }


        vector<pair<int,int>> directions={{0,1},{1,0},{0,-1},{-1,0}};

        int cnt=0;

        while(!pq.empty()){
            int r=pq.front().first.first;
            int c=pq.front().first.second;
            int t=pq.front().second;

            time=max(time,t);
            pq.pop();

            for(auto& dir:directions){
                int rn=r+dir.first;
                int cn=c+dir.second;
                 
                 if(rn>=0 and rn<n and cn>=0 and cn<m  and vis[rn][cn]==0 and grid[rn][cn]==1){
                    cnt++;
                    pq.push({{rn,cn},time+1});
                    vis[rn][cn]=1;
                 
                 }

            }
        }
         if (cnt != cntFresh) return -1;

         return time;


        
    }



        

};