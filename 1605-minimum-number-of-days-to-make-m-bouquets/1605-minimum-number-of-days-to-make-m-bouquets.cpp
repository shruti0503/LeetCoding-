class Solution {
public:
    bool check(vector<int>& arr,int m,int k, int mid){
        int total=0;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            
            if(arr[i]<=mid){
                
                cnt++;
                if(cnt==k){
                total++;
                cnt=0;
                }
            }
            else
                cnt=0;
            
        }
        if (total>=m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s=0;
        int ans=0;
        if(((long long) m*k)>bloomDay.size()){
            return -1;
        }
        // int e=bloomDay.size()-1;
        int e=*max_element(bloomDay.begin(), bloomDay.end());
        // int e=INT_MAX-1;
        while(s<=e){
            int mid=s+(e-s)/2;
           if( check(bloomDay,m,k,mid)){
               ans=mid;
               e=mid-1;
           }
            else{
                s=mid+1;
            }
            
        }
        return ans;
        
    }
};