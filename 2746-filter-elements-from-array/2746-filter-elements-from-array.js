/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

 //immperitive programming
var filter = function(arr, fn) {
//   return  arr.filter(fn);
    const res=[];
    for(let i=0;i<arr.length;i++){
        if(fn(arr[i],Number(i))){
            res.push(arr[i]);
        }
    }
    return res;
    
};