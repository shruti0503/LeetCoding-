class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (isVowel(s[i]) && isVowel(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            } else if (isVowel(s[i])) {
                j--;
            } else {
                i++;
            }
        }
        return s;
    }
    
    bool isVowel(char c) {
        c = tolower(c); 
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
