function findMaxConsecutiveOnes(nums: number[]): number {
    //1 1 0 1 1 1
    let max:number=0;
    let ans:number=0;
    for(let num of nums){
        if(num===0) max=0;
        else max++;
        ans=Math.max(max, ans);


    }
    return ans;
};