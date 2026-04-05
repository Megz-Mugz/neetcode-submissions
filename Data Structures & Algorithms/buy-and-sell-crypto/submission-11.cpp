class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 1;
        int max_profit = 0;

        while (sell < prices.size()){

            while (sell < prices.size() && prices[buy] < prices[sell]){
                max_profit = std::max(prices[sell] - prices[buy], max_profit);
                sell++;
            }
            buy = sell;
            sell++;
        }

        return max_profit;
    }
};
