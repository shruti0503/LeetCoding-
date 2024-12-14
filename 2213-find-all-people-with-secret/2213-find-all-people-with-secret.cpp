class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
       vector<vector<pair<int, int>>> adj(n);

        for(auto it: meetings){
            // [1,2,5] , 1->2 , 5
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        //{time , person};
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0}); //person 
        pq.push({0, firstPerson});
        vector<int>vis(n,0);

        while(!pq.empty()){
            auto it=pq.top();
            int time=it.first;
            int person=it.second;

            pq.pop();
            if(vis[person]){ // if already visited that means , usse secret pta h
                continue;
            }
            vis[person]=true;
            for(auto it:adj[person]){
                if(!vis[it.first] and it.second>=time){
                    pq.push({it.second, it.first});
                }

            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]){
                ans.push_back(i);
            }
        }

        return ans;



    }
};