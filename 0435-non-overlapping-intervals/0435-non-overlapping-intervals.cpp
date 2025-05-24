class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), comp);
        int cnt = 1;
        int prev = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= prev) {
                cnt++;
                prev = intervals[i][1];
            }
        }

        return intervals.size() - cnt;
    }
};