class Solution {
public:

  void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int sr, int sc, int color, int oldColor) {
     if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor || ans[sr][sc] == color) {
           return;
      }


     ans[sr][sc]=color;
     dfs(image, ans, sr+1, sc, color,oldColor);
     dfs(image, ans, sr-1, sc, color, oldColor);
     dfs(image, ans, sr, sc+1, color, oldColor);
     dfs(image, ans, sr, sc-1, color,oldColor);
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // m n 
        // pixel value of the image.
        //image[sr][sc]
        // color -> fill neighbouring cells -> same color
        // if they match the same color as the color[sr][sc]

        // image[sr][sc]=1  -> color =2 
        // if  adjcent cells are also the color 1 then color those too with the 2

        int oldColor=image[sr][sc];
        if(oldColor!=color){ // they shouldn't be same 
            vector<vector<int>>ans=image;
            dfs(image, ans, sr, sc, color, oldColor);
            return ans;
        }
        return image;

    }
};