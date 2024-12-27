class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // we can rearraange this formula 
        // values[i] + values[j] + i - j
        // -> values[i]+i + (values[j]-j);
        // so upto j particular index , tak 
        // we can compute best (values[i]+i)
        // intially it will be -> values[0]
        int max_i=values[0];
        int maxScore=0;
        for(int j=1;j<values.size();j++){
            maxScore=max(maxScore, max_i+ values[j]-j);
            max_i=max(max_i , values[j]+j);
        }
        return maxScore;
    }
};