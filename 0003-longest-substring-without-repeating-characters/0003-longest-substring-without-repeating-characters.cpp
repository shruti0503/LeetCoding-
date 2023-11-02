class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ldss(256,0); // ascii code of a-z,  space, A-Z, digits fall under the number range of 0 - 255
        int i = 0, n = s.size(), j = 0;
        int ans = 0;
        while(i < n)
        {
            if(ldss[s[i]] == 1)
            {
                ldss[s[j]]--;
                j++;
            }
            else
            {
                ldss[s[i]]++;
                ans = max(ans, i-j+1);
                i++;
            }
        }
        return ans;
    }
};