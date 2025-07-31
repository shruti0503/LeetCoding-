

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxVal = n * n;
        vector<int> freq(maxVal + 1, 0);
        
        // Count frequencies of each number in grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                freq[grid[i][j]]++;
            }
        }
        
        int repeated = -1, missing = -1;
        for (int num = 1; num <= maxVal; ++num) {
            if (freq[num] == 2) repeated = num;
            else if (freq[num] == 0) missing = num;
        }
        
        return {repeated, missing};
    }
};
