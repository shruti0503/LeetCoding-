class Solution {
public:
 void func(int n, int k, vector<int>&ds, vector<vector<int>>& ans, int ind){

    //base case
    if(k==0){
         ans.push_back(ds);
         return;

    }
    if(ind>n){
    // ans.push_back(ds);
     return;
    }
    //pick 
    ds.push_back(ind);
    func(n, k-1, ds, ans, ind+1);  ds.pop_back(); 
    // you do not need to manually revert the value of k after a recursive call because each recursive call operates with its own copy of k. When you pass k - 1 to a recursive call, this new value of k is only relevant within the scope of that particular call. The original value of k remains unchanged in the calling function, so there is no need to manually increment k back after the call.

    // not pick
     func(n, k, ds, ans, ind+1); 


 }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ds;
        vector<vector<int>> ans;
        func(n, k, ds, ans, 1);

        return ans;
        
    }
};