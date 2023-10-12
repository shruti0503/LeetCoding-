class Solution {
public:
// 2-> rotten
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(); // row
        int m=grid[0].size(); // col

        // storing in row col pai
        queue<pair<pair<int,int>,int>>pq;

      vector<vector<int>> vis(n, vector<int>(m,0));
      // if the cell has the rotten organges i mark as visited , we wioll not visit it after wards
      int cntFresh=0;
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(grid[i][j]==2){
                  vis[i][j]=2; 
                  pq.push({{i, j}, 0}); 
              } 
              // count fresh oranges
            if (grid[i][j] == 1) cntFresh++;
          }
      }

      int time=0;
      int delr[]={-1,0,+1,0};
      int delc[]={0,1,0,-1};
      int cnt=0;

      // bfs traversal
      while(!pq.empty()){
          int r=pq.front().first.first;
          int c=pq.front().first.second;
          int t=pq.front().second;
          time=max(time,t);
          pq.pop();
    // cause there are 4 neighbours
      for(int i=0;i<4;i++){
          // neighbouring row and col
          int nrow=r+delr[i];
          int ncol=c+delc[i];
          if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0 and grid[nrow][ncol]==1){
              // push in queue with timer increased
             pq.push({{nrow, ncol}, time + 1}); 
            // mark as rotten
            vis[nrow][ncol] = 2;
            cnt++;

          }
      }
      }

// if all oranges are not rotten
      if (cnt != cntFresh) return -1;

      return time;
        
    }
};