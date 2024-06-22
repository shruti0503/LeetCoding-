class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //so i have to buy the stock whn the price is minium
        // and sell it to attain the max profit
        int mxProfit=0;
        int minPrice=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minPrice=min(minPrice,prices[i]);
            mxProfit=max(mxProfit,(prices[i]-minPrice));
        }
        return mxProfit;
        
    }
};