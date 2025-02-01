class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int>pq;

        for(auto i:nums){
            pq.push(i);
        }
        int num=k;

        while(num>1){
            num--;
            pq.pop();
        }

        return pq.top();
        
    }
};