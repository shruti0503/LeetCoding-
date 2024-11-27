class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    // Sort both greed factors and cookie sizes
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0; // pointer for children
    int j = 0; // pointer for cookies

    // Traverse both arrays
    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) {
            // If the cookie satisfies the child's greed
            i++; // move to the next child
        }
        // Move to the next cookie regardless of whether it satisfied the child or not
        j++;
    }

    return i; // i represents the number of content children
}
};