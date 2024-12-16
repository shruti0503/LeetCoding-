class Solution {
public:

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& oceans, int i ,int j ,int n,int m){
        if(i<0 || i>n-1 || j<0 || j>m-1) return;
        if(!oceans[i][j]){ // if not visisted
          //mark vis 
          oceans[i][j]=1;
          // should be a valid index and height must be greater than the current

          if(i-1>=0 && heights[i-1][j]>=heights[i][j]) dfs(heights,oceans,i-1,j,n,m);
            if(i+1<n && heights[i+1][j]>=heights[i][j]) dfs(heights,oceans,i+1,j,n,m); 
            if(j-1>=0 && heights[i][j-1]>=heights[i][j]) dfs(heights,oceans,i,j-1,n,m);
            if(j+1<m && heights[i][j+1]>=heights[i][j]) dfs(heights,oceans,i,j+1,n,m);

        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>pacific(n, vector<int>(m,0));
        vector<vector<int>>atlantic(n, vector<int>(m,0));
        vector<vector<int>>ans;
        // boundaries se shrur
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0){
                    if(!pacific[i][j]){
                        dfs(heights, pacific, i, j , n, m);
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==n-1 || j==m-1){
                    dfs(heights, atlantic, i , j , n , m);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] and atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }


        return ans;
    }
};