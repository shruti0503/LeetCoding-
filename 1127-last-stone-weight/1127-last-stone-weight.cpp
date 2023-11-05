class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        
        for(auto it: stones){
            pq.push(it);
        }

        while(pq.size()>1){
            int x=pq.top(); pq.pop();
            int y= pq.top(); pq.pop();

            

            if(x==y and (pq.size()==0)){
                pq.push(0);
                continue;
            }
            else if(x!=y){
                int y1=abs(y-x);
                pq.push(y1);
            }
            
        }
        return pq.top();
    }
};