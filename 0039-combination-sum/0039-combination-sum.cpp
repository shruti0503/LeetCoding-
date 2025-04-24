class Solution {
public:
  void func(vector<int>& cand, int target, int ind, vector<vector<int>>& ans, vector<int> curr){


    if(ind==cand.size()){
          if(target==0){
            ans.push_back(curr);
          }
       return ;

    }

  

    //pick eklemt
    if(cand[ind]<=target){
        curr.push_back(cand[ind]);
        // it should not ne ind+1 as we are allowed to use same elemnt
        func(cand, target-cand[ind], ind, ans, curr);
        curr.pop_back();
    }

    //not pick
     func(cand, target, ind+1, ans, curr);


  }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        func(candidates, target, 0, ans, curr);
        return ans;
    }
};