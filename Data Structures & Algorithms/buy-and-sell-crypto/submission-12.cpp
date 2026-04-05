class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;

        int buy_ptr = 0, sell_ptr = 1;
        int N = prices.size();

        while (sell_ptr < N){
            if (prices[buy_ptr] < prices[sell_ptr]){
                max_profit = std::max(max_profit, 
                            prices[sell_ptr] - prices[buy_ptr]);
            } else {
                buy_ptr = sell_ptr;
            }
            sell_ptr++;
        }


        return max_profit;
    }
};
