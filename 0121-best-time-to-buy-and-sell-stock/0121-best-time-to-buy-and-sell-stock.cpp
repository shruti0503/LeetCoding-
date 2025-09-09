class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy -> lowestv 
        // sell highest
        int buy=prices[0];
        int sell=0;
        int profit=0;
        // 
        for(int i=1;i<prices.size();i++){
            int sell=prices[i];
            profit=max(profit, sell-buy);
            buy=min(buy,prices[i]);

        }
        return profit;
    }
};