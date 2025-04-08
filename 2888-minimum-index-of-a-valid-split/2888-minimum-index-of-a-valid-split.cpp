class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // x  -> arr
        // more than half -> dominant
        // 2,1, 3,1,1,1, 7,1,2,1
        // 1-> 6
        // int cnt1=0;

        // int num1=0;
        // for(auto num:nums){
        //     if(cnt1==0) num1=num;
        //     if(num==num1) cnt++;
        //     else cnt1=1;
        // }
        // return num1;

        int n=nums.size();
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }
        int ele=-1;
        for(auto entry:freq){
            if(entry.second>n/2){
                ele=entry.first;
                break;
            }
        }
        if(ele==-1) return -1;
        int totalCount=freq[ele];
        int leftCount=0;
        int rightCount=totalCount;
        for(int i=0;i<n-1;i++){
            if(nums[i]==ele) leftCount++;
            if(nums[i]==ele) rightCount--;
            if(leftCount*2>(i+1) && rightCount*2>(n-i-1)){
                return i;
            }
        }
        return -1;
        
    }
};