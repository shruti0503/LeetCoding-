class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indeg(numCourses,0);
        vector<vector<int>>adjList(numCourses);
        for(auto courses:prerequisites){
            indeg[courses[0]]++;
            adjList[courses[1]].push_back(courses[0]);
        }
        queue<int>pq;
        for(int i=0;i<indeg.size();i++){
           if(indeg[i]==0){
             pq.push(i); // push the node
           }
        }
        //vector<pair<int,int>>  del={{0,1},{1,0},{-1,0}, {0,-1}};
        vector<int>topo;
        while(!pq.empty()){
            int node=pq.front();
            pq.pop();
            topo.push_back(node);
            for(auto adj:adjList[node]){
                indeg[adj]--;
                if(indeg[adj]==0) {
                    pq.push(adj);
                }
            }
        }

       return topo.size()==numCourses ? true: false;

       


    }
};