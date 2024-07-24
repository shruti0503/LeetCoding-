class Solution {
public:
   void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis){
     // checking for out of bbounds
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || vis[i][j]) {
            return;
     }
     vis[i][j]=true;
     dfs(grid, i-1, j, vis);
     dfs(grid, i+1, j, vis);
     dfs(grid, i, j - 1, vis); // Left
     dfs(grid, i, j + 1, vis); // Right

   }
    int numIslands(vector<vector<char>>& grid) {

        int res=0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));

        //iterate over each cell in the grid
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' and !vis[i][j]){
                    res++; // count of island
                    dfs(grid, i, j , vis);

                }

            }
        }

        return res;
        
    }
};