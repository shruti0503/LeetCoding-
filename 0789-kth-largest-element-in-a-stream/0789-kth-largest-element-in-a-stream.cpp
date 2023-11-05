class KthLargest {
public:
 priority_queue<int, vector<int>,greater<int>>pq;
 int cnt;
    KthLargest(int k, vector<int>& nums) {
        //maintaing the k size heasp
       
         cnt=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>cnt) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>cnt) pq.pop();
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */