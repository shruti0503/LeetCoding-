class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) return result;
        
        int start = nums[0];
        int end = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == end + 1) {
                end = nums[i];  // Expand the current range
            } else {
                if (start == end) {
                    result.push_back(to_string(start));  // Single number, no range
                } else {
                    result.push_back(to_string(start) + "->" + to_string(end));  // Add the range
                }
                
                start = nums[i];  // Start a new range
                end = nums[i];
            }
        }
        
        // Handle the last range
        if (start == end) {
            result.push_back(to_string(start));  // Single number, no range
        } else {
            result.push_back(to_string(start) + "->" + to_string(end));  // Add the range
        }
        
        return result;
    }
};
