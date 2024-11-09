class Solution {
public:
// First, we will form the adjacency list of the graph using the pairs. For example, for the pair {u, v} we will add node v as an adjacent node of u in the list.
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        //creating adj c list;
        vector<int> adj[n];
        //add the index of the prewq course to th list of incoming edges for the dependnt source in the adj list.

        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
            //adj[i[i]] or  adj[it.first] = accessing list of seconf elemnet
            //adj[i[1]].push_back(i[0]);
            // it.first =access the second elemnt of of 'it', which represents course that depends on the prereq.
        }
        vector<int>topo;
        //calculate the indegree
        //iterarte through the givem adj list and simply for every node u->v, we can increse the indegree v by 1 in the indgree arr
        vector<int> indegree(n,0);
        for(int node=0;node<n;node++){
            for(auto j:adj[node]){
                indegree[j]++;
            }
        }
    //initally there will alwasys be  at least a single node whose indegree is 0.
    //so push it in queue.
    queue<int>q;
        for(int node=0;node<n;node++){
            if(!indegree[node]){
                q.push(node);
            }
        }
    //pop a node from the queue includng the node in our own topo aarray and for all the adjcant nodes, decrese the indegree of that node by one.

        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                 if(!indegree[it]) q.push(it);
                
            }
            //if for any node the indegree becomes zero;push that node again in queue.
           
        }

        if(topo.size()!=n){
            return {};
        }

        return topo;

    }
};