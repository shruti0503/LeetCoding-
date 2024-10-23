class Solution {
public:
    bool isGood(vector<int>& nums) {
      map<int,int> st;
        int maxele=*max_element(nums.begin(), nums.end());

        for(auto it: nums){
            st[it]++;

        }
        
        for(auto it:st ){
            
            if(it.first!=maxele and it.second>1){
                return false;
                
            }
            
            if(it.first==maxele and it.second!=2){
                return false;
                
            }
            

        }
        
        return st[nums.size()-1] == 2;
        
    }
};