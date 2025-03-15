class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n, vector<int>(m,INT_MAX));


        queue<pair<int,int>>pq;
       // int n=pq.size()
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    pq.push({i,j});
                    ans[i][j]=0;

                } 
            }
       }

       vector<vector<int>>dir={{0,1}, {1,0}, {-1,0},{0,-1}};

        while(!pq.empty()){
            auto pos=pq.front();
            pq.pop();
            int row=pos.first;
            int col=pos.second;

            for(auto d:dir){
                int r=d[0]+row;
                int c=d[1]+col;

                if(r>=0 and r<n and c>=0 and c<m){
                    if(ans[r][c]>ans[row][col]+1){
                        ans[r][c]=ans[row][col]+1;
                        pq.push({r,c});
                    }
                }

            }


        }

        return ans;
    }
};