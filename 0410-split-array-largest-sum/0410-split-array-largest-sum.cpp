class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=low;
        while(low<=high){
            int mid=(low+high)/2;
            int n=no_of_subarrayWithmaxSumof_mid(nums,mid);
            if(n>m){
                low=mid+1;
                
            }
            else{
                ans=mid;
                high=mid-1; //to get  a better ans
            }
        }
        return ans;
        
    }
    int no_of_subarrayWithmaxSumof_mid(vector<int> arr,int mid){
        int sum=0;
        int cnt=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]+sum>mid){
                sum=arr[i];
                cnt++;

                
            }
            else{
                sum+=arr[i];

            }

        }
        return cnt;

    }
};