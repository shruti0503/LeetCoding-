class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses,0);
        for(auto course:prerequisites){
            adj[course[1]].push_back(course[0]);
            indeg[course[0]]++;
        }
        queue<int>pq;
        vector<int>topo;

        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0){
                pq.push(i);
            }
        }

        while(!pq.empty()){
            int course=pq.front();
            pq.pop();
            topo.push_back(course);
            for(auto adjNode:adj[course]){
                indeg[adjNode]--;
                if(indeg[adjNode]==0){
                    pq.push(adjNode);
                }
            }
        }

        if(topo.size()==numCourses){
            return topo;
        }

        return {};
        
    }
};