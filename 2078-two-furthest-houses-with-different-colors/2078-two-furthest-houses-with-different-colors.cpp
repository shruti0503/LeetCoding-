class Solution {
public:
//brutte force for each number check whether any nuberr is diff cur currennt and and calculate the max distance
    int maxDistance(vector<int>& colors) {
    int maxd=INT_MIN;
    int dist=0;
    int ans=INT_MIN;
     int res=0;
        for(int i=0;i<colors.size();i++){
            for(int j=0;j<colors.size()-1;j++){
                if(colors[i]!=colors[j]){
               dist=abs(i-j);
                }
               
               
              ans=max(dist,ans);
// 1 8 3 8 3
//op :4
//i=0 j=1 dist =1 max: min,1=1
//i=0, j=2 dist=2 max: 1,2=2
//i=0, j=3 NT VALID
//i=0 , j=4 dist=4 max: 2,4=4

            }
        }
        return ans;
        
    }
};