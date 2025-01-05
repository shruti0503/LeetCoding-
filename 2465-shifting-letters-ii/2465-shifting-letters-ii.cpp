class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
           int n = s.size();
    vector<int> diff(n + 1, 0);

    // difference array
    for (auto& shift : shifts) {
        int start = shift[0], end = shift[1], direction = shift[2];
        if (direction == 1) {
            diff[start] += 1;
            diff[end + 1] -= 1;
        } else {
            diff[start] -= 1;
            diff[end + 1] += 1;
        }
    }

    //   cumulative sum
    int cumulative = 0;
    for (int i = 0; i < n; ++i) {
        cumulative += diff[i];
        // shift to the currennt characte
        int shiftValue = (s[i] - 'a' + cumulative) % 26;
        if (shiftValue < 0) shiftValue += 26;
        s[i] = 'a' + shiftValue;
    }

    return s;
    }
}; 

// s = "abc", shifts = [[0, 1, 0], [1, 2, 1], [0, 2, 1]]

// Initialize the Difference Array:

// diff = [0, 0, 0, 0]  // One extra space for easier boundary handling
// Process the Shifts:

// For [0, 1, 0] (backward shift):

// diff[0] -= 1  // Start the backward shift at index 0
// diff[2] += 1  // Stop the backward shift after index 1
// diff = [-1, 0, 1, 0]
// For [1, 2, 1] (forward shift):

// diff[1] += 1  // Start the forward shift at index 1
// diff[3] -= 1  // Stop the forward shift after index 2
// diff = [-1, 1, 1, -1]
// For [0, 2, 1] (forward shift):

// diff[0] += 1  // Start the forward shift at index 0
// diff[3] -= 1  // Stop the forward shift after index 2
// diff = [0, 1, 1, -2]
// Cumulative Sum (Net Shifts):

// Compute the cumulative sum of diff to determine the net shift for each character:

// cumulative = [0, 1, 2, 0]  // Ignoring the extra space
// Apply Shifts to the String:

// For each character in s:
// Shift 'a' (index 0) by 0 → 'a'
// Shift 'b' (index 1) by 1 → 'c'
// Shift 'c' (index 2) by 2 → 'e'
// Result: "ace"