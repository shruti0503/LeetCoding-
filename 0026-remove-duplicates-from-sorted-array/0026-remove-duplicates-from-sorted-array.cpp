class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i=0;
        for(int j=i;j<arr.size();j++){
            if(arr[i]!=arr[j]){
                i++;
                arr[i]=arr[j];
            }
        }
        return i+1;
        
    }
};