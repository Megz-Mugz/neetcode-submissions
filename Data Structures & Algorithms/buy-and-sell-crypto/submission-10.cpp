class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_ptr = 0;
        int sell_ptr = 1;
        int total_profit = 0;

        while (sell_ptr < prices.size()){
            
            if (prices[buy_ptr] < prices[sell_ptr]){
                total_profit = std::max(prices[sell_ptr] - prices[buy_ptr], total_profit);
                sell_ptr++;
            } else {
                // move pointers
                buy_ptr = sell_ptr;
                sell_ptr++;
            }
            
        }

        return total_profit;
    }
};
