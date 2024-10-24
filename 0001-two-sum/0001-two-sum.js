/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    // Store both numbers and their original indices
    let numWithIndex = nums.map((num, index) => [num, index]); 
    
    // Sort based on the number values (not indices)
    numWithIndex.sort((a, b) => a[0] - b[0]);
    
    let i = 0;
    let j = numWithIndex.length - 1;
    
    while (i < j) {
        let sum = numWithIndex[i][0] + numWithIndex[j][0];
        
        if (sum === target) {
            // Return the original indices of the two numbers
            return [numWithIndex[i][1], numWithIndex[j][1]];
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }
    
    // If no solution is found
    return [];
};
