class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n=intervals.size();
        int i=0;
        //intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
        while(i<n and intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]); 
            i++;
        }
        //[[1,2]]
        //now merge the overlapping 
        while(i<n and intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0], intervals[i][0]);
            newInterval[1]=max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};