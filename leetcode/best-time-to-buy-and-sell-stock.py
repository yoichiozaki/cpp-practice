class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        min_sofar = prices[0]
        for i in range(1, len(prices), 1):
            profit = max(profit, prices[i] - min_sofar)
            min_sofar = min(min_sofar, prices[i])
        return profit
