class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;

        }
        for(auto it:mpp){
            pq.push({it.second,it.first});
            
        }
        int p;
        char m;
        string st;
        while(!pq.empty()){
            m=pq.top().second;
            p=pq.top().first;
            if(p==1){
                st+=m;

            }
            else{
                while(p--){
                    st+=m;
                }

            }
            pq.pop();
        }
        return st;
        
    }
};