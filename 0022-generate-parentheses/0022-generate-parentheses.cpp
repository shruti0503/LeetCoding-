class Solution {
public:

   void func(int ind, vector<string>& ans, int n, int open, int close, string &s){
       if(ind==n){
        ans.push_back(s);
        return;
       }
       if(open>0 and ind!=n-1){
        s+="(";
        func(ind+1,ans, n, open-1, close,s);
        s.pop_back();
       }
       if(close>0 && open<close){
        s+=')';
        func(ind+1,ans,n,open,close-1,s);
        s.pop_back();
       }
       return;
   }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        func(0, ans,2*n, n, n, s);
        return ans;
        
    }
};