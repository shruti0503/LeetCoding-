class Solution {
public:
   bool valid(int mid, vector<int>& piles, int h, int & ans){
    long long sum=0;
    for(int i=0;i<piles.size();i++){
        sum+=(long long) ceil((double)piles[i]/mid);
    }
    cout<<"sum for "<<mid<< " is "<<sum<<endl;
    if(sum<=h){
        ans=mid;
        cout<<" coco can  mid is (sum<=h) "<< mid<<endl;
        cout<<"coco can with sum "<< sum<<endl;
        return true;
    }
    else{
        cout<<"coco cannot with mid"<<mid<<endl;
        cout<<"coco cannot with sum"<<sum<<endl;
        return false;
    }

   }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=*max_element(piles.begin(), piles.end());
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(valid(mid, piles, h,ans)){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return ans;
        
    }
};