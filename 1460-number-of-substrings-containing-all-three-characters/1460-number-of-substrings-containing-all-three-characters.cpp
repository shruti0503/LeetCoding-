class Solution {
public:
    int numberOfSubstrings(string s) {
        //check out note
        // abcabc 
        // a b c
        // a->3 
        // b -> 1
        // c-> 1
        //aaa bc 
        int left=0;
        int right=0;
        int count=0;
        unordered_map<char, int> mpp;
        while(right<s.size()){
            mpp[s[right]]++;

            while(mpp['a']>0 and mpp['b']>0 and mpp['c']>0){
                count+=s.size()-right;
                mpp[s[left]]--;
                left++;
            }
            right++;

        }
        return count;


    }
};