class Solution {
public:
bool canTransform(string start, string target) {
    int n = start.size();
    
    // Check if both strings contain the same number of L's and R's
    if (count(start.begin(), start.end(), 'L') != count(target.begin(), target.end(), 'L') ||
        count(start.begin(), start.end(), 'R') != count(target.begin(), target.end(), 'R')) {
        return false;
    }

    int i = 0, j = 0;
    
    while (i < n && j < n) {
        // Skip over blanks in both strings
        while (i < n && start[i] == '_') i++;
        while (j < n && target[j] == '_') j++;
        
        // Both are at the end of the strings
        if (i == n && j == n) break;
        
        // One of them is at the end but the other is not
        if (i == n || j == n) return false;

        // Compare positions of L's and R's
        if (start[i] != target[j]) return false;

        // For 'L' we must be able to move left
        if (start[i] == 'L' && i < j) return false;

        // For 'R' we must be able to move right
        if (start[i] == 'R' && i > j) return false;

        // Move to the next piece
        i++;
        j++;
    }
    
    return true;
}
    bool canChange(string start, string target) {
     
    return canTransform(start, target);

        
    }
};