class ProductOfNumbers {
public:
    //stack<int>st;
    vector<int>arr;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        //st.push(num);
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int num=k;
        int prod=1;
        //stack<int>s=st;
        // while(i>=1 and s.size()){
        //     int num=s.top();
        //     s.pop();
        //     prod*=num;
        //     i--;
        // }
        int n=arr.size()-1;
        for(int i=n;i>=0 and num>=1 ;i--){
           // cout<<"arr"<<arr[i]<<endl;
            prod*=arr[i];
            num--;
        }
        return prod;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */