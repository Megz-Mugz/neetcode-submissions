class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buyPtr = 0;
        int sellPtr = 1;
        int totalProfit = 0;

        while (sellPtr < prices.size()){
            if (prices[buyPtr] < prices[sellPtr]){
                totalProfit  = std::max(prices[sellPtr] - prices[buyPtr], totalProfit);
            } else { 
                // in the event the sell price is lower than the buy price, you move buy price
                buyPtr = sellPtr;
            }
            sellPtr++;
        }
        return totalProfit;
    }
};
