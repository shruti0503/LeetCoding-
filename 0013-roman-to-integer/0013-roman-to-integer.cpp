class Solution {
public:
//  each character:
// Retrieve its integer value from the romanValues map.
// Determine the value of the next character (if it exists).
// If the current value is smaller than the next value, subtract the current value from the result.
// Otherwise, add the current value to the result.
    int romanToInt(string s) {
        unordered_map<char, int> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
        int currentVal = romanValues[s[i]];
        int nextVal = (i + 1 < s.length()) ? romanValues[s[i + 1]] : 0;

        if (currentVal < nextVal) {
            result -= currentVal;
        } else {
            result += currentVal;
        }
    }

    return result;

    }
};