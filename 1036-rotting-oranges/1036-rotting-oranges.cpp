class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
      queue<pair<pair<int, int>, int>> pq; 
         vector<vector<int>> vis(n, vector<int>(m, 0));

        // push rot ones in queue
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    pq.push({{i,j}, 0});
                }
                else if(grid[i][j]==1){
                   cnt++;
                }
            }
        }
        int time=0;
        vector<pair<int,int>> del={{-1,0}, {0,1}, {1,0},{0,-1}};

        while(!pq.empty()){
             auto [position, currTime]=pq.front();
             int row=position.first;
             int col=position.second;
             pq.pop();
             time= max(time, currTime);
             for(auto [dRow, dCol]:del){
                int nRow=row+dRow;
                int nCol=row+ dCol;

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && vis[nRow][nCol] != 2) {
                    pq.push({{nRow, nCol}, currTime + 1});
                    vis[nRow, nCol]=2;
                    cnt--;
                }
             }
        })

        return cnt == 0 ? time : -1;
        
    }
};