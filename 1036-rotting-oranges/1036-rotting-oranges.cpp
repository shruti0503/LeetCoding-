// fresh ko count karo , rot ko queue mai daalo
// end mai check karo fresh ka count agr zero hai toh time ko returhn kr do

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        int n=grid.size();
        int m=grid[0].size();
        int time=0;
       queue<pair<pair<int, int>, int>> pq;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m ;j++){
                if(grid[i][j]==2){
                    pq.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        vector<pair<int,int>> del={{-1,0}, {0,1}, {1,0}, {0,-1}};
        while(!pq.empty()){
            auto [pos, currTime]=pq.front();
            int row=pos.first;
            int col=pos.second;
            pq.pop();

            time=max(time, currTime);
            for(auto [dRow, dCol]:del){
                int nRow=row+dRow;
                int nCol=col+dCol;

                if(nRow>=0 and nRow<n and nCol>=0 and nCol<m and grid[nRow][nCol]==1
                and  vis[nRow][nCol]!=2){
                    pq.push({{nRow, nCol}, currTime+1});
                    vis[nRow][nCol]=2;
                    fresh--;
                }
            }
        }

        return fresh==0 ? time : -1;


        
    }
};