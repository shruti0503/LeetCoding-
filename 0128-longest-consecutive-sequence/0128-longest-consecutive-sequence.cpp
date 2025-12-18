class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int longestStreak = 1;
        int currentStreak = 1;

        for (int i = 1; i < nums.size(); i++) {
            // Skip duplicates
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            // Consecutive number
            else if (nums[i] == nums[i - 1] + 1) {
                currentStreak++;
            }
            // Break in sequence
            else {
                currentStreak = 1;
            }

            longestStreak = max(longestStreak, currentStreak);
        }

        return longestStreak;
    }
};