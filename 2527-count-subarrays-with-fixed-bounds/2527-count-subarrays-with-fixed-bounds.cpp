class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
      int start=0;
      bool minfactor,maxfactor=false;
      long long cnt=0;
      int minid,maxid=0;
      for(int i=0;i<nums.size();i++){
          //vheck for termination condition
          int n=nums[i];
          if(n>maxK || n<minK){
              //start new
              minfactor=false;
              maxfactor=false;
              start=i+1;
          }
          if(n==minK){
              //store its index
               minid=i;
              minfactor=true; //minifacor mil gya
          }
          if(n==maxK){
              //store its index
               maxid=i;
              maxfactor=true;
          }
          //agar minK aur maxK dono mil gye
          if(maxfactor && minfactor){
              cnt+=(min(minid,maxid)-start+1);
          }
    
      }
      return cnt;
    }
};