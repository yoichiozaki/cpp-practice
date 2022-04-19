class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # dp[i]: i円支払うのに必要な硬貨の最小枚数
        dp = [float("inf") for _ in range(1 + amount)]
        dp[0] = 0
        for i in range(1, 1 + amount):
            for coin in coins:
                if 0 <= i - coin:
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        return dp[amount] if dp[amount] != float("inf") else -1