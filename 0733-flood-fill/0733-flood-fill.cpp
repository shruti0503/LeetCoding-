class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int sr, int sc, int color, int oldColor) {
        // Check if we're out of bounds or if the cell is already the color we want
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || ans[sr][sc] == color || image[sr][sc] != oldColor) {
            return;
        }

        // Set the color
        ans[sr][sc] = color;

        // Move in all four directions
        dfs(image, ans, sr + 1, sc, color, oldColor);
        dfs(image, ans, sr - 1, sc, color, oldColor);
        dfs(image, ans, sr, sc + 1, color, oldColor);
        dfs(image, ans, sr, sc - 1, color, oldColor);
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        // Only start DFS if the color is different
        if (oldColor != color) {
            vector<vector<int>> ans = image;
            dfs(image, ans, sr, sc, color, oldColor);
            return ans;
        }
        return image;
    }
};
