class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // initliase adjaceny lkist
        vector<vector<int>>adj[n+1];
        for(const auto& time: times){
            int src=time[0];
            int target=time[1];
            int weight=time[2];
            adj[src].push_back({target, weight});
        }
        // min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        vector<int> dist(n+1, INT_MAX);
        dist[k]={0};
        pq.push({k,0});
        while(!pq.empty()){
            int currDist=pq.top().second;
            int node=pq.top().first;
            pq.pop();

            // if the distance in the queue is greater than the current known distance,
            // skip processing ; coz no point if the currDist is already grrater that mneans its already gonna reach this one too
            if(currDist>dist[node]) continue;

            for(const auto&  adjs: adj[node]){
                int adjNode=adjs[0];
                int weight=adjs[1];

                // relaxation
                if(dist[node]+weight<dist[adjNode]){
                    dist[adjNode]=dist[node]+weight;
                    pq.push({adjNode,dist[adjNode]});
                }

            }

        }

        int maxDist= *max_element(dist.begin()+1, dist.end());
        return maxDist==INT_MAX ? -1 : maxDist;
        
    }
};