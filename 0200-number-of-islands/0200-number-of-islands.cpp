class Solution {
public:

    void bfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& vis){

        int rows=grid.size();
        int cols=grid[0].size();

        queue<pair<int,int>>pq;
        pq.push({r,c});

        vector<pair<int,int>> directions={{0,1},{1,0}, {0,-1}, {-1, 0}};

        while(!pq.empty()){
            auto [i,j]=pq.front();
            pq.pop();

            for(auto dir:directions){
                // {0,1}
                int ni=i+dir.first;
                int nj=j+dir.second;

                if(ni>=0 and ni<rows and nj>=0 and nj<cols and grid[i][j]=='1' and !vis[ni][nj]){
                    pq.push({ni,nj});
                    vis[ni][nj]=true;
                }

            }
        }
    
    }

    int numIslands(vector<vector<char>>& grid) {

        if(grid.empty()) return true;
        int res=0;
        int rows=grid.size();
        int cols=grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1' and !visited[i][j]){
                    res++;
                    bfs(grid, i, j, visited);
                }
            }
        }

        return res;
        
    }
};