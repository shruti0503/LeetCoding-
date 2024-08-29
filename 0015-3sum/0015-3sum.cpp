class Solution {
public:
   vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
      vector<vector<int>> ans;

        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i!=0 and nums[i]==nums[i-1]) continue; // i ka duplicate skip krne k liye
            int j=i+1;
            int k=n-1;
            // teen pointers fix h ab
            // i j and k 
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                if(sum<0){
                    j++;

                }
                else if (sum==0){
                    // make a vector and push in and
                    vector<int> temp={nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // skip duplicates
                    while(j<k and nums[j]==nums[j-1]) j++;
                    while(j<k and nums[k]==nums[k+1]) k--;
                }
            }


        }
        return ans;

}
};