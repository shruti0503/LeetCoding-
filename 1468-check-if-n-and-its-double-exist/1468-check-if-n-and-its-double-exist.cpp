class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
       
        unordered_map<int, int>mpp;
        for(int i=0;i<arr.size();i++){
           mpp[arr[i]]=i;
        }
        // 10-0
        // 2-1

        for(int i=0;i<arr.size();i++){
            cout<<"2*arr[i] "<<2*arr[i]<<endl;
            cout<<"i is " <<i<<endl;
            cout<<"arr[i] "<<arr[i]<<endl;
             cout<<"mpp[arr[i]] "<<mpp[arr[i]]<<endl;
            if((mpp.count(2*arr[i]) and mpp[2*arr[i]!=i])){
                return true;
            }
            if(arr[i]%2==0 and mpp.count(arr[i]/2) and mpp[arr[i]/2]!=i){
                return true;
            }
        }
        return false;
        
    }
};