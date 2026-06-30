class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        buy = 0
        sell = 1

        while (sell < prices.size()){
            if sell < buy -> buy = sell
        
        }
        */

        int max_profit = 0;

        int buy_ptr = 0;
        int sell_ptr = 1;

        while (sell_ptr < prices.size()){
            
            // ensure the buying price is less than the selling price
            if (prices[sell_ptr] < prices[buy_ptr]){
                buy_ptr = sell_ptr;
                sell_ptr++;
                continue;
            }
            // compute profit
            max_profit = std::max(max_profit, prices[sell_ptr] - prices[buy_ptr]);
            sell_ptr++;
        }

        return max_profit;
    }
};
