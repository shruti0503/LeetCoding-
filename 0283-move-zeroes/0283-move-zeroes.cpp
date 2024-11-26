class Solution {
    //brute force app would be to take a sep array and push forst all the non zero elements and 
    //then travserse again and push all the zeros
    //sc o(n) tco(n)
public:
// Initial vector: {0, 1, 0, 3, 12}
// lastNonZeroFoundAt = 0, cur = 0

// // First iteration: cur = 0
// nums[0] = 0, which is zero, so we don't do anything

// // Second iteration: cur = 1
// nums[1] = 1, which is not zero, so we swap it with nums[lastNonZeroFoundAt]
// nums: {1, 0, 0, 3, 12}, lastNonZeroFoundAt = 1

// // Third iteration: cur = 2
// nums[2] = 0, which is zero, so we don't do anything

// // Fourth iteration: cur = 3
// nums[3] = 3, which is not zero, so we swap it with nums[lastNonZeroFoundAt]
// nums: {1, 3, 0, 0, 12}, lastNonZeroFoundAt = 2

// // Fifth iteration: cur = 4
// nums[4] = 12, which is not zero, so we swap it with nums[lastNonZeroFoundAt]
// nums: {1, 3, 12, 0, 0}, lastNonZeroFoundAt = 3

// // Loop is done, all the zeroes are at the end of the vector
// Final vector: {1, 3, 12, 0, 0}


    void moveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt], nums[cur]);
            lastNonZeroFoundAt++;
        }
    }
}
};
