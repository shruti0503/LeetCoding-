class Solution {
public:
    int maxScore(string s) {
        // s
        // s-> 
        // 0s + 1s
        int zeros=0;
        int ones=0;
        int n=s.size();
        for(auto it:s){
            if(it=='1'){
                ones++;
            }
            if(it=='0'){
                zeros++;
            }
        }

        if (zeros==0 || ones==0){
            return n-1;
        }

        if(n==2 and s[0]=='0'){
            return 2;

        }
        else if(n==2 and s[0]=='1'){
            return 0;
        }

        vector<int>Ones(n,0);
        vector<int>Zeros(n,0);
        for(int i=0;i<s.size();i++){
            if(i!=0){
                Zeros[i]=Zeros[i-1];
            }
            if(s[i]=='0'){
                
                Zeros[i]++;
                cout<<"i "<< i << " Zeros[i] "<< Zeros[i]<<endl;
            }
            if(i==n-1){
                Zeros[i]--;
            }

            
            
        }
        for(int i=n-1;i>=0;i--){
            if(i!=n-1){
                Ones[i]=Ones[i+1];
            }
            if(s[i]=='1'){
                Ones[i]++;
            }
            if(i==0){
                Ones[i]--;
            }
           
            
        }
        int maxScore=INT_MIN;
        for(int i=0;i<n;i++){
            int sum=0;
            sum=Ones[i]+Zeros[i];
            cout<<"ones "<<i<<" "<<Ones[i]<<" ";
            cout<<"zeros "<<Zeros[i]<<endl;
            maxScore=max(sum, maxScore);
        }

        return maxScore;

        
    }
};