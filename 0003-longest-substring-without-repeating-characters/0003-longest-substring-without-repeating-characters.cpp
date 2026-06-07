class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;  // to store unique characters in the current window
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.length(); ++right) {
            // Expand the window by adding the character at 'right'
            while (window.find(s[right]) != window.end()) {
                // If character is already in the window, shrink the window by moving 'left'
                window.erase(s[left]);
                left++;
            }
            // Add the current character to the window
            window.insert(s[right]);
            // Update the maximum length of the substring
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};