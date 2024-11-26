class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        
        // Calculate indegree for each node
        for (auto& edge : edges) {
            indegree[edge[1]]++;
        }
         for (auto& edge : indegree) {
            cout<<edge<<endl;
        }
        
        // Find the node(s) with indegree 0
        int champion = -1;
        
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (champion == -1) {
                    champion = i;  // Found the first node with indegree 0
                    cout<<"found champion "<< i << endl;
                } else {
                    return -1;  // More than one node with indegree 0
                     cout<<" no found champion "<<  endl;
                }
            }
        }
        
        // If no node with indegree 0, there is no champion
        if (champion == -1) {
            return -1;
        }
        
        // Check if the champion has any outgoing edges
        // for (auto& edge : edges) {
        //     if (edge[0] == champion) {
        //         return -1;  // The champion has an outgoing edge, so it's not unique
        //     }
        // }
        
        // If the champion has no outgoing edges, it's the unique champion
        return champion;
    }
};
