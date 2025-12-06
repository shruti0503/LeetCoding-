class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0,j=0;
        int n=colors.size();
        int total=0;//totaltime
        while(i<n && j<n){
            int maxTime=0;
            int currTotal=0;
            while(j<n && colors[i]==colors[j]){
                maxTime=max(maxTime,neededTime[j]);
                currTotal+=neededTime[j];
                j++;
            }
            i=j;
            total+=(currTotal-maxTime);
            
            
        }
        return total;
        
    }
};