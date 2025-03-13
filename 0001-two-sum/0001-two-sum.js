/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {

    const seen={}; // empty object to store previsuly seen numbers and their indices 
    let result =[]; // to store indices of two numbers that sum up to the target 

    for(let i=0;i<nums.length;i++){ // iterates through each number in the nums array
        const comp =target-nums[i]; // calculates the comp of the current number that would make up the target sum
        if(seen.hasOwnProperty(comp)){ //checking is the comp has already been seen in the 'seen' Object
            result=[seen[comp],i]; // If the complement is found, stores its index and the current index in the result array.
            return result; 
        }

        seen[nums[i]]=i;
    }
    console.log(result)

    return result;

    
};