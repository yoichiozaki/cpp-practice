# buy -> cooldown -> sell
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit_at_buy = float("-inf")
        profit_at_sell = 0
        profit_at_cooldown = 0
        for price in prices:
            profit_at_buy, profit_at_sell, profit_at_cooldown = max(profit_at_buy, profit_at_cooldown - price), max(profit_at_sell, profit_at_buy + price), max(profit_at_cooldown, profit_at_sell)
        return max(profit_at_sell, profit_at_cooldown)