class Solution {
public:

   bool canReach(vector<vector<int>>& heights, int maxEffort){
        int n=heights.size();
        int m=heights[0].size();
        queue<pair<int,int>>pq;
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        pq.push({0,0});
        vis[0][0]=true;

        vector<pair<int,int>>directions={{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!pq.empty()){
            auto [row,col]=pq.front();
            pq.pop();
            if(row==n-1 and col==m-1) return true;

            for(auto dir:directions){
                int nrow=row+dir.first;
                int ncol=col+dir.second;

                if(nrow>=0 and ncol>=0 and nrow<=n-1 and ncol<=m-1 and !vis[nrow][ncol]){
                    if(abs(heights[nrow][ncol]-heights[row][col])<=maxEffort){
                        vis[nrow][ncol]=true;
                        pq.push({nrow, ncol});
                    }
                }
            }

        }

        return false;


   }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        int left=0;
        int right=1000000;
        int result=right;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(canReach(heights, mid)){
                result=mid;
                right=mid-1; // try for smaller max effort
            }
            else{
                left=mid+1;
            }
        }

        return result;
        
    }
};