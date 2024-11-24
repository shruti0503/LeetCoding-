class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 7, 1 , 5 , 3 , 6 , 4 
        // brute force -> two loops O(n2)

        // consider each as current price while updating the
int maxProfit=0;
        int minPrice=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minPrice=min(minPrice, prices[i]); // 7 
            maxProfit=max(maxProfit, prices[i]-minPrice); // 
        }

        return maxProfit;
        



    }
};