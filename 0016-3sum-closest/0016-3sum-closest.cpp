class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
        int n = a.size();
        sort(a.begin(), a.end());

        int closest = a[0] + a[1] + a[2];

        for (int i = 0; i <= n - 3; i++)
        {
            int left = i + 1;
            int right = n - 1;
            
            // Just like Two Sum Approach
            while (left < right)
            {
                int curSum = a[i] + a[left] + a[right];
                if (curSum == target)
                {
                    return curSum;
                }
                if (curSum < target)
                {
                    if (abs(closest - target) > abs(curSum - target))
                    {
                        closest = curSum;
                    }
                    left++;
                }
                else
                {
                    if (abs(closest - target) > abs(curSum - target))
                    {
                        closest = curSum;
                    }
                    right--;
                }
            }
        }
        return closest;
    }
};