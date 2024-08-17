class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int>mpp;
        for(auto i:s){
            mpp[i]++;
        }
        for(auto i:t){
            //element is found bedfore end of map
            if(mpp.find(i)!=mpp.end()){
                mpp[i]--;
            }
            else{
                return false;
            }
        }

        for(auto i:mpp){
            if(i.second!=0) return false;
        }

        return true;

    }
};