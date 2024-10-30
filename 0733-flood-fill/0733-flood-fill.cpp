class Solution {
public:

 void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int initialColor, int color, int n , int m) {
    if((row<0 || row>=n || col <0 || col>=m)  ||  ans [row][col]!=initialColor) return ;

    ans[row][col]=color;
       dfs(row+1, col, ans, image, initialColor, color,n, m); 
         dfs(row-1, col, ans, image, initialColor, color,n, m);
 dfs(row, col+1, ans, image, initialColor, color,n, m);
    dfs(row, col-1, ans, image, initialColor, color,n, m); 
    
 
    

  }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // change the colour of adj if same 
        vector<vector<int>> ans = image;
        int initialColor = image[sr][sc];
        int n=image.size();
        int m=image[0].size();
       
       // vector<vector<int>>
         if (initialColor != color) { // chekcing if the inital cell is alreacy  the target color 
            dfs(sr, sc, ans, image, initialColor, color, n, m);
        }
       return ans;

    }
};