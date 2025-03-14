class Solution {
public:
     void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int sr, int sc, int color, int oldcolor){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || ans[sr][sc]==color || image[sr][sc]!=oldcolor){
            return;
        }
        ans[sr][sc]=color;

        dfs(image, ans, sr+1, sc, color, oldcolor);
        dfs(image, ans, sr-1, sc, color, oldcolor);
        dfs(image, ans, sr, sc+1, color, oldcolor);
        dfs(image, ans, sr, sc-1, color, oldcolor);
     }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans;
        int oldcolor=image[sr][sc];
        if(oldcolor!=color){
            vector<vector<int>>ans=image;
            dfs(image, ans,sr,sc, color, oldcolor);
            return ans;
        }
        return image;
        
    }
};