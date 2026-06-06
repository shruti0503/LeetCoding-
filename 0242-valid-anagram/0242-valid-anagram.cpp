class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s==t;
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>mpp;

        for(char ch:s){
            mpp[ch]++;
        }
        for(char ch:t){
            mpp[ch]--;
        }
        for(pair<char,int> ch:mpp){
            if(ch.second>0) return false;
        }
        return true;

        
    }
};