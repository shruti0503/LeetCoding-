class Solution {
public:
   
    string pushDominoes(string dominoes) {
         
         int n=dominoes.size();
        vector<int> left(n,0) , right(n,0);
        //right traversal
        int cnt=1;
        int prev='.';
        
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                prev='R';
                cnt=1;
                continue;
            }
            else if(dominoes[i]=='L'){
                prev='L';
                
            }
            if(prev=='R' && dominoes[i]=='.'){
                right[i]=cnt;
                cnt++;

            }
        }
        
        //for left array traversal
        cnt=1;
        prev='.';
        
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L'){
                prev='L';
                cnt=1;
                continue;
            }
            else if(dominoes[i]=='R'){
                prev='R';
                
            }
            if(prev=='L' && dominoes[i]=='.'){
                left[i]=cnt;
                cnt++;

            }
        }
        
        //final result
        string finalResult="";
        for(int i=0;i<n;i++){
            if(left[i]==0 && right[i]==0){
                finalResult+=dominoes[i];
            }
            else if(left[i]==0){
                finalResult+='R';

            }
            else if(right[i]==0){
                finalResult+='L';

            }
            else if(left[i]==right[i]){
                finalResult+='.';
            }
            else if(left[i]>right[i]){
                finalResult+='R';
            }
            else{
                finalResult+='L';

            }

        }
        return finalResult;
        
        
         
        
    }
};