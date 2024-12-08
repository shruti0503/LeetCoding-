class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // [1,3]
         vector<vector<int>>ans;
         if(intervals.size()==0){
            return ans;
         }
         sort(intervals.begin(), intervals.end());
         vector<int> temp=intervals[0];
         for(auto it:intervals){ // [1,3]
           cout<<"interval  start it "<< it[0]<<endl;
            if(it[0]<=temp[1]){
                cout<<"end interval " << temp[1]<<endl;
                temp[1]=max(it[1], temp[1]);
                cout<<"merge it "<< temp[0]<<" "<<temp[1]<<endl<<endl;
            }
            else{
                ans.push_back(temp);
                temp=it;
            }
         }
         ans.push_back(temp);
         return ans;
    }
};