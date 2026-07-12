class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // [li, ri]
        // 1 4  , 3 6  ,2 8
        // 1 4  2 8 3 6
        // int[i][0] <= int[j][0] and int[i][1]>=int[j][1] -> convered -> break
        // sort intervals by increasing start (and decreasing end for equal starts), 
        // then count an interval only if its end extends beyond the maximum end seen so far
        // otherwise, it is covered by a previous interval.
        sort(intervals.begin(), intervals.end(),[](vector<int>&a, vector<int>& b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int count=0;
        int maxEnd=0;
        for(auto &interval:intervals){
            if(interval[1]>maxEnd){
                count++;
                maxEnd=interval[1];
            }
        }
        return count;

 
    }
};