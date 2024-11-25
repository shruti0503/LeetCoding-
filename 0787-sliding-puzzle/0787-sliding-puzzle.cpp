class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        string target = "123450";
        
        // Convert the 2D board into a string representation
        for (const auto& row : board) {
            for (int num : row) {
                start += to_string(num);
            }
        }
        
        // Predefined neighbors for each position in the string
        vector<vector<int>> neighbors = {
            {1, 3},        // 0
            {0, 2, 4},     // 1
            {1, 5},        // 2
            {0, 4},        // 3
            {1, 3, 5},     // 4
            {2, 4}         // 5
        };
        
        queue<pair<string, int>> q; // Queue to store {current state, depth}
        unordered_set<string> visited; // To track visited states
        
        q.push({start, 0});
        visited.insert(start);
        
        while (!q.empty()) {
            auto [current, depth] = q.front();
            q.pop();
            
            if (current == target) return depth; // Found the solution
            
            int zeroPos = current.find('0'); // Find the position of '0'
            
            for (int neighbor : neighbors[zeroPos]) {
                string next = current;
                swap(next[zeroPos], next[neighbor]); // Swap '0' with its neighbor
                
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push({next, depth + 1});
                }
            }
        }
        
        return -1; // If no solution is found
    }
};
