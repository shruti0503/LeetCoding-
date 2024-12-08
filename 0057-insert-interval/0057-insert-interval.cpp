class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // can insert an interval only when 
        //it[1]>new[0];
        // temp [1,2] 
        // [[1,2] [3,8]  ]
        // temp=[3,8]
         vector<vector<int>>ans;
        if(intervals.empty()) return{newInterval};
        intervals.push_back(newInterval);
         //[[1,3],[2,6],[8,10],[15,18]]
         // temp=[1,3]
         //[1,3]  temp[1]>=it[0] ->  temp[1]-> max of both -> temp=[1,6]
         // [8,10]
         // ans -> [[1,6] ,    ]
         // temp= [8,10] it=[15,18];  15>10 so cannot merge -> temp=[15,18]
         // [[1,6] , [8,10]]

         sort(intervals.begin(), intervals.end());
         vector<int> temp=intervals[0];
         for(auto it:intervals){ // [1,3]
           cout<<"interval  start it "<< it[0]<<endl;
            if(it[0]<=temp[1]){
                cout<<"end interval " << temp[1]<<endl;
                temp[1]=max(it[1], temp[1]);
                temp[0]=min(it[0], temp[0]);
                cout<<"merge it "<< temp[0]<<" "<<temp[1]<<endl<<endl;
            }
            else{
                ans.push_back(temp);
                temp=it;
            }
         }
         ans.push_back(temp);
         return ans;
         
         // newInterval=[2,5]
        //  for(it:intervals){
    
        //  }
    }
};