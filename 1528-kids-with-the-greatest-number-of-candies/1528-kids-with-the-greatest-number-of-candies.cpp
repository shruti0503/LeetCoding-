class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extracandies) {
          vector<bool>ans;
        int maxele=*max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();i++){
            if((candies[i]+extracandies)>=maxele){
                ans.push_back(true);

            }
            else ans.push_back(false);
        }
        return ans;
        
    }
};