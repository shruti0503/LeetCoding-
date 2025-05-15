function moveZeroes(nums: number[]): void {
    let lastNonZero = 0;

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) {
            [nums[i], nums[lastNonZero]] = [nums[lastNonZero], nums[i]];
            lastNonZero++;
        }
    }
}
