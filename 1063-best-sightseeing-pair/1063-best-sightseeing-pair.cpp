class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_i=values[0];
        int maxScore=0;
        for(int j=1;j<values.size();j++){
            maxScore=max(maxScore, max_i+ values[j]-j);
            max_i=max(max_i , values[j]+j);
        }
        return maxScore;
    }
};