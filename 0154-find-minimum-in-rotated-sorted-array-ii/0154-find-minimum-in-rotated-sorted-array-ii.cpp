// Initial Observation: In a sorted array, the minimum element is always at the beginning (index 0). However, due to rotation, the minimum element can be shifted towards the middle or end of the array.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] < nums[e]) {
                e = mid;  // Focus on the left side of the array.
            } else if (nums[mid] >nums[e]) {
                s = mid + 1;  // Focus on the right side of the array.
            } else {
                e--;  // Handle duplicates, move towards the potential minimum.
            }
        }

        return nums[s];
    }
};
