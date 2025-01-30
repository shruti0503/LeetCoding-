class Solution {
public:
// brute force -> for each index: amount of water taht can be stored
// amount of water stores= diff of min and max elevation left and right - heioght of the particular index
// TC O(n*n)

    // int trap(vector<int>& height) {
    //     int n=height.size();
    //     int waterTrapped=0;
    //     for(int i=0;i<n;i++){
    //         int j=i;
    //         int leftMax=0, rightMax=0;
    //         while(j>=0){
    //             leftMax=max(leftMax,height[j]);
    //             j--;
    //         }
    //         j=i;
    //         while(j<n){
    //             rightMax=max(rightMax,height[j]);
    //             j++;

    //         }
    //         waterTrapped+=min(leftMax,rightMax)-height[i];
    //     }
    //     return waterTrapped;
        
    // }

    // BETTER SOLUTION
    //We are taking O(N) for computing leftMax and rightMax at each index. The complexity can be boiled down to O(1) if we precompute the leftMax and rightMax at each index.
    // USING PREFIX AND SUFFIX ARRAY 
    //  int trap(vector<int>& height) {
    //     int n=height.size();
    //     vector<int>prefix(n); // need to specify size too; else runtime error
    //     vector<int>suffix(n);
    //     prefix[0]=height[0];
    //     for(int i=1;i<n;i++){
    //         prefix[i]=max(prefix[i-1],height[i]);
    //     }
    //     suffix[n-1]=height[n-1];
    //     for(int i=n-2;i>=0;i--){
    //         suffix[i]=max(suffix[i+1],height[i]);
    //     }
    //     int waterTrapped=0;
    //     for(int i=0;i<n;i++){
    //         waterTrapped+=min(prefix[i],suffix[i])-height[i];
    //     }
    //     return waterTrapped;

    //  }
     // TC O(3N) + O(5N) SC: O(N)+O(N)

     // OPTIMAL APPROACH
     // take 2 pointers l and r
     // two variables leftMax and rightMax
      int trap(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1;
        int res=0;
        int maxLeft=0;
        int maxRight=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=maxLeft){
                    maxLeft=height[l];
                }
                else{
                    res+=maxLeft-height[l];
                }
                l++;
            }
            else{
                if(height[r]>=maxRight){
                    maxRight=height[r];
                }
                else{
                    res+=maxRight-height[r];
                }
                r--;   
            }

        }
        return res;

      }

};