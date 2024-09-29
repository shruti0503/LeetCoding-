class Solution {
public: 
  bool isPali( string str, int s, int e){
    while(s<=e){
        if(str[s++]!=str[e--]){
            return false;
        }

    }
    return true;
  }
   void func(int ind, string s , vector<vector<string>>& res, vector<string>& path){
    
     if(ind==s.size()){
        res.push_back(path);
        return;
     }
     for(int i=ind ;i<s.size() ; i++){
         if(isPali(s, ind , i)){
            path.push_back(s.substr(ind, i-ind+1));
            func(i+1, s, res, path);
            path.pop_back();
         }
        
       
     }
   }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string>path;
        func(0,s,res,path);
        return res;
    }
};