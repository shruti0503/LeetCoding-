class Solution {
public:
int count(int spell, vector<int>& potions, long long success, vector<int>& ans){
    int mid;
    int s=0;
    int mids=potions.size();
    int e=potions.size()-1;

    while(s<=e){
         int mid = s + (e - s) / 2;

        long long prod= (long long) spell * potions[mid];
         
         if(prod>=success){
             mids=mid;
             e=mid-1;
         }
         else{
             s=mid+1;
         }

    }

      return (potions.size()-mids);

}
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans(spells.size());
        sort(potions.begin(), potions.end());

        for(int i=0;i<spells.size();i++){
            ans[i]=count(spells[i],potions, success, ans);
        }
        return ans;
        
    }
};