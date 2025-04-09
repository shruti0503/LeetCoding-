class ProductOfNumbers {
public:
    vector<int>arr;
    int prod=1;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        arr.push_back(num);
    
    }
    
    int getProduct(int k) {
        int num=k;
        int prod=1;
        int n=arr.size()-1;
        for(int i=n;i>=0 and num>=1 ;i--){
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