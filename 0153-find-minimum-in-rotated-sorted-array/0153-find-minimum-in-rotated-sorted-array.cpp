class Solution {
public:

// Check Mid with Last Element: Compare 'nums[mid]' with 'nums[e]' (the last element of the current search range).

// - If 'nums[mid]' is greater than 'nums[e]', it indicates that the minimum element lies in the right half of the array. Update 's' to 'mid + 1' to focus the search on the right side.

// - If 'nums[mid]' is less than or equal to 'nums[e]', it indicates that the minimum element may exist in the left half of the array or at 'mid'. Update 'e' to 'mid' to consider the current 'mid' element as a potential minimum.

// End Loop: Continue the loop until 's' is no longer less than 'e'.

// Return Minimum: The loop ends when 's' becomes equal to 'e', and the minimum element is found at 'nums[s]'. Return 'nums[s]' as the minimum element.

    int findMin(vector<int>& nums) {
       int s=0;
       int e=nums.size()-1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        return nums[s];

      

    }
};