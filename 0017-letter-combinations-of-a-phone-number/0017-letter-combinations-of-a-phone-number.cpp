class Solution {
public:
   
   void func(string digits, string curr, int ind, string mapp[], vector<string>& ans){
    if(ind>=digits.size()){
        ans.push_back(curr);
        return;
    }
    int digit=digits[ind]-'0'; // extract that partivcular digit
    string val=mapp[digit]; // map it to its corresponidng alphabets string
    for(int i=0;i<val.size();i++){ // start traversing  -> and make the corresponding combinations
        curr.push_back(val[i]); // push it toc cure 
        func(digits,curr, ind+1, mapp, ans); // make tyhe further crecursive call 
        curr.pop_back(); // while  returning backtrack and pop out the last entereed 
    }
   }
    vector<string> letterCombinations(string digits) {
         string mapping[10]={"","","abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
         vector<string>ans;
         if(digits.size()==0){
            return ans;
         }
         func(digits, "", 0 , mapping, ans);
         return ans;
    }
};