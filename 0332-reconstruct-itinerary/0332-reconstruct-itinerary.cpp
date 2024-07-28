class Solution {
public:
  void dfs(const string& str, unordered_map<string, vector<string>>& adj, vector<string>& res){
    auto& destinations=adj[str];
    while(!destinations.empty()){
        string next=destinations.front();
        destinations.erase(destinations.begin());
        dfs(next, adj, res);

    }
    res.push_back(str);
  }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // sort the tickets so that we get in lexical order
        sort(tickets.begin(), tickets.end());
        // vector<vector<char>> adj;
        unordered_map<string, vector<string>> adj;
        for(auto tick:tickets){
            adj[tick[0]].push_back(tick[1]);
        }

        vector<string> res;
       // res.push_back("JFK");
         dfs("JFK", adj, res);

        reverse(res.begin(), res.end());
        return res;
        
    }
};