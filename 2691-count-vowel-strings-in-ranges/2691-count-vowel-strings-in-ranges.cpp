class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // [li , ri
        unordered_set<char>vowels={'a', 'e', 'i', 'o', 'u'};
        int n=words.size();
        vector<int>prefix(n,0);
        for(int i=0;i<n;i++){
            char first=words[i][0];
            char last=words[i].back();
            if(vowels.count(first) and vowels.count(last)){
                prefix[i]=1;
            }
            if(i>0){
                prefix[i]+=prefix[i-1];
            }
        }
        vector<int>result;
        for(auto query: queries){
            int l=query[0];
            int r=query[1];
            if(l==0){
                result.push_back(prefix[r]);
            }
            else{
                result.push_back(prefix[r]-prefix[l-1]);
            }
        }
        return result;



    }
};