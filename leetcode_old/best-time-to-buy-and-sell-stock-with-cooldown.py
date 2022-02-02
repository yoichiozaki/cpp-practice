class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        profit_at_buy = float("-inf")  # 買いの直後の利益
        profit_at_sell = 0  # 売りの直後の利益
        profit_at_stay = 0  # cooldown直後の利益
        for i in range(n):
            profit_at_buy, profit_at_sell, profit_at_stay = max(profit_at_buy, profit_at_stay - prices[i]), max(
                profit_at_sell, profit_at_buy + prices[i]), max(profit_at_stay, profit_at_sell)
        return max(profit_at_sell, profit_at_stay)
