/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */

 //Method 1

// var reduce = function(nums, fn, init) {
//     let val=init;
//     for(let i=0;i<nums.length;i++){
//         val=fn(val,nums[i]);
//     }
//     return val;
// };

// METHOD 2
// var reduce = function(nums, fn, init) {
//     let val=init;
//     for(const i of nums){ //used 'of' as we are accessing directly values
//         val=fn(val,i);
//     }
//     return val;
// };

//METHOD 3
// var reduce=function(nums,fn,init){
//     let val=init;
//     nums.forEach((n)=> val=fn(val,n));
//     return val;
// }

//METHOD 4 directly use reduce function
var reduce =function(nums,fn,init){
    return nums.reduce(fn,init)
   
}