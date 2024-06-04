class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
         if(x==0) return 0;
         if(n==0) return 1;
         long long N;
        if(n<0){
            x=1/x;
            n=abs(n);
        }
        long long temp=n;
        while(temp>0){
            if(temp%2==1){ //odd -> multiple the result by the current base
               res*=x;

            }
            //sqaure the base
            x*=x;
            temp/=2; // half the exponent
        }

        return res;
        
    }
};