class Solution {
public:
    int characterReplacement(string s, int k) {

      unordered_map<char, int> charCount;  
        int left = 0;             // Left pointer
        int maxCount = 0;         // To keep track of the maximum character count
        int result = 0;           // To store the maximum length of substring

        for (int right = 0; right < s.size(); ++right) {
            charCount[s[right]]++;  // Update the character count for the current character

            // Update the maximum character count in the current window
            maxCount = max(maxCount, charCount[s[right]]);

            // Calculate the size of the current window and check if it can be improved
            if (right - left + 1 - maxCount > k) {
                // If the window size exceeds k, shrink the window by moving the left pointer
                charCount[s[left]]--;  // Remove the left character from the window
                left++;               // Move the left pointer to the right
            }

            // Update the result with the maximum window size
            result = max(result, right - left + 1);
        }

        return result;

        
    }
};