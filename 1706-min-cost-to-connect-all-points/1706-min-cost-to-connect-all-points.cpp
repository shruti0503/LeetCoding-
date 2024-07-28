// Initialization: minDist keeps track of the minimum distance to add a node to the MST,
// initialized to INT_MAX for all nodes except the starting node (0). inMST keeps track of which nodes are
//  included in the MST.

// Main Loop: In each iteration, the algorithm selects the node with the
//  smallest edge cost not in the MST, adds it to the MST, 
//  and then updates the minimum distances for its adjacent nodes.

// Updating Edges: For each node added to the MST, update the cost to connect to each non-MST node.

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n=points.size();
        int edgesUsed=0;
        vector<bool>inMST(n);
        vector<int>minDist(n,INT_MAX);
        minDist[0]=0;
        int result=0;

        while(edgesUsed<n){
            int currMinEdge=INT_MAX;
            int currNode=-1;
            // greedily pick the lowest node in mst
            for(int i=0;i<n;i++){
                if(!inMST[i] && currMinEdge>minDist[i]){
                    currMinEdge=minDist[i];
                    currNode=i;
                }
            }
            result+=currMinEdge;
            edgesUsed++;
            inMST[currNode]=true;
            //update adj nodes of currnode
            for(int i=0;i<n;i++){
            int cost = abs(points[currNode][0] - points[i][0]) + abs(points[currNode][1] - points[i][1]);

                if(!inMST[i] and minDist[i]>cost){
                    minDist[i]=cost;
                }
            }
        }

        return result;
        
    }
};