class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        profit = 0
        buy_ptr = 0
        sell_ptr = 1

        while sell_ptr < len(prices):
            if prices[buy_ptr] >= prices[sell_ptr]:
                buy_ptr = sell_ptr
            else:
                profit = max(profit, prices[sell_ptr] - prices[buy_ptr])
            sell_ptr += 1
        
        return profit
