class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left=0;
        int right=0;
        int ans=INT_MAX;
        int cnt=0;
        while(right<blocks.size()){
            if(blocks[right]=='W'){
                cnt++;
            }
            if(right-left+1==k){
                ans=min(cnt,ans);
                if(blocks[left]=='W'){
                    cnt--;
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};