class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        bottom_price = float("+inf")
        max_profit = 0

        for price in prices:
            max_profit = max(max_profit, price - bottom_price)
            bottom_price = min(bottom_price, price)
        return max_profit