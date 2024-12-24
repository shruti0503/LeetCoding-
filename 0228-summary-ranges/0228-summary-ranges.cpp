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
                end = nums[i];  // expand  current range
            } else {
                if (start == end) {
                    result.push_back(to_string(start));  
                } else {
                    result.push_back(to_string(start) + "->" + to_string(end));  
                }
                
                start = nums[i];  // sttart  new range
                end = nums[i];
            }
        }
        

        if (start == end) {
            result.push_back(to_string(start));  // single numbr, no range
        } else {
            result.push_back(to_string(start) + "->" + to_string(end));  // add  range
        }
        
        return result;
    }
};
