class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         std::vector<int> result;
    std::deque<int> dq;

    for (int i = 0; i < nums.size(); ++i) {
        // Remove indices that are outside the current window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Remove smaller elements from the back of the deque
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Add maximum element to the result array
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
    }
};