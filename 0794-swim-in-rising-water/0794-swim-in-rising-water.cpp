class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size(); 
        vector<vector<int>> vis(n, vector<int>(m, INT_MAX)); // visited matrix
        priority_queue<vector<int> , vector<vector<int>>, greater<vector<int>>> pq; //pq
        pq.push({grid[0][0],0,0}); // initaly first block
        vector<pair<int,int>>directions={{0,1},{1,0},{0,-1},{-1,0}}; // directions in which swimmer can go
        vis[0][0]=grid[0][0];// mark as visited

        while(!pq.empty()){
            auto curr=pq.top(); // pop out  curr block
            pq.pop();
            int currTime=curr[0]; // first one is the possition current
            int row=curr[1]; // row 
            int col=curr[2]; //col
            if(row==n-1 and col==m-1) return currTime ;  // return the time 
            for(auto dir:directions){ // move in all four directions
               int newRow=row+dir.first;
               int newCol=col+dir.second;
               if(newRow>=0 and newRow<n and newCol<m and newCol>=0){ //check if within bounds
                   int newTime=max(currTime, grid[newRow][newCol]); // the time to reach the new cell is the max of the currTime and the height of the new cell
                   if(newTime<vis[newRow][newCol]){// we have found a quicker way 
                       vis[newRow][newCol]=newTime;
                       pq.push({newTime, newRow, newCol});

                   }


               }

            }
        }


        return -1; //in case no way to reach bottom right;


        
    }
};