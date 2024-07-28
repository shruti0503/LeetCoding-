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

// Sure, let's break down the `dfs` function and go through a dry run with an example to better understand how it works.

// ### DFS Function Explanation:

// 1. **Reference to Adjacency List**:
//    - `auto& destinations = adj[airport];`
//    - This line gets a reference to the list of destinations from the current airport to avoid copying the list.

// 2. **While Loop**:
//    - `while (!destinations.empty()) { ... }`
//    - The loop runs as long as there are destinations to visit from the current airport.

// 3. **Processing Destinations**:
//    - `string next = destinations.front();`
//    - This line takes the first destination from the list (lexically smallest due to sorting).
//    - `destinations.erase(destinations.begin());`
//    - This line removes the first destination from the list after it is chosen.
//    - `dfs(next, adj, result);`
//    - This line calls `dfs` recursively for the chosen destination.

// 4. **Adding to Result**:
//    - `result.push_back(airport);`
//    - After all destinations from the current airport are processed, the current airport is added to the result.

// ### Dry Run Example:

// Let's use the following tickets as an example:
// ```
// tickets = [["JFK", "SFO"], ["JFK", "ATL"], ["SFO", "ATL"], ["ATL", "JFK"], ["ATL", "SFO"]]
// ```

// **Step-by-Step Dry Run**:

// 1. **Sort the Tickets**:
//    ```
//    [["ATL", "JFK"], ["ATL", "SFO"], ["JFK", "ATL"], ["JFK", "SFO"], ["SFO", "ATL"]]
//    ```

// 2. **Build Adjacency List**:
//    ```
//    adj = {
//        "ATL": ["JFK", "SFO"],
//        "JFK": ["ATL", "SFO"],
//        "SFO": ["ATL"]
//    }
//    ```

// 3. **Start DFS from "JFK"**:
//    - `dfs("JFK", adj, result)`

// 4. **First Call (JFK)**:
//    - Destinations: ["ATL", "SFO"]
//    - Choose "ATL"
//    - `dfs("ATL", adj, result)`

// 5. **Second Call (ATL)**:
//    - Destinations: ["JFK", "SFO"]
//    - Choose "JFK"
//    - `dfs("JFK", adj, result)`

// 6. **Third Call (JFK)**:
//    - Destinations: ["SFO"]
//    - Choose "SFO"
//    - `dfs("SFO", adj, result)`

// 7. **Fourth Call (SFO)**:
//    - Destinations: ["ATL"]
//    - Choose "ATL"
//    - `dfs("ATL", adj, result)`

// 8. **Fifth Call (ATL)**:
//    - Destinations: ["SFO"]
//    - Choose "SFO"
//    - `dfs("SFO", adj, result)`

// 9. **Sixth Call (SFO)**:
//    - Destinations: []
//    - No more destinations, add "SFO" to result: `result = ["SFO"]`
//    - Return to Fifth Call

// 10. **Back to Fifth Call (ATL)**:
//     - No more destinations, add "ATL" to result: `result = ["SFO", "ATL"]`
//     - Return to Fourth Call

// 11. **Back to Fourth Call (SFO)**:
//     - No more destinations, add "SFO" to result: `result = ["SFO", "ATL", "SFO"]`
//     - Return to Third Call

// 12. **Back to Third Call (JFK)**:
//     - No more destinations, add "JFK" to result: `result = ["SFO", "ATL", "SFO", "JFK"]`
//     - Return to Second Call

// 13. **Back to Second Call (ATL)**:
//     - No more destinations, add "ATL" to result: `result = ["SFO", "ATL", "SFO", "JFK", "ATL"]`
//     - Return to First Call

// 14. **Back to First Call (JFK)**:
//     - No more destinations, add "JFK" to result: `result = ["SFO", "ATL", "SFO", "JFK", "ATL", "JFK"]`

// 15. **Final Result**:
//     - Reverse the result to get the correct order: `["JFK", "ATL", "JFK", "SFO", "ATL", "SFO"]`

// ### Summary

// The `dfs` function processes each node (airport) by always choosing the lexically smallest destination first 
//(due to the sorted tickets). 
//It recursively visits each destination and finally adds the
// current airport to the result after all its destinations are processed.
// The result list is then reversed to get the correct itinerary.