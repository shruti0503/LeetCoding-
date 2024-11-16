class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //one simple approach for O(N) complexity qoud bw
        //run a while loo and check for each number if present or not
        //while(size of array){
       // }
        
        //optimised approach
        //smallest and larget index
        //check for mid 
        //if the element is check for the  umber of mising element at that index by 
        //nums[mid]-mid ; taking one based indexing
        //if the difference is less ; move the small poiner to mid+1 ; else end=mid-1

        // int lo = 0, hi = arr.size();
        // while (lo < hi) {
        //     int mid = lo + (hi - lo) / 2;
        //     if (arr[mid] - mid > k) hi = mid;
        //     else lo = mid + 1;
        // }
        // return hi + k;

        int s=0;
        cout<<"starting s "<< s<<endl;
        int e=arr.size();
        cout<<"ending index "<<e<<endl<<endl;
         
         while(s<e){
           
             int mid=s+(e-s)/2;
              cout<<"mid is "<<mid<<endl;
               cout<<"checking arr[mid] is "<<arr[mid]<<endl;
               cout<<" checking (arr[mid]-mid) "<<arr[mid]-mid<<endl<<endl;;
             if((arr[mid]-mid)>k){
                 //cout<<"arr[mid] is "<<arr[mid]<<endl;
                 cout<<"(arr[mid]-mid)>k case"<<arr[mid]-mid<<endl;
                 e=mid;

             }
             else{
                cout<<"else case now s will be "<<mid+1<<endl<<endl;
                 s=mid+1;;
             }
            

         }
          return e+k;

    }
};