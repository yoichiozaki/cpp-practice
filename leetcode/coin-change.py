class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # dp[i][j]: i番目までのコインを使ってj円を実現するときの最小枚数
        # dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]] + 1)
        coins = [-1] + coins
        INF = 10 ** 9
        dp = [[INF for _ in range(amount + 1)] for _ in range(len(coins))]
        for i in range(len(coins)):
            dp[i][0] = 0
        for i in range(1, len(coins)):
            for j in range(amount + 1):
                if 0 <= j-coins[i]:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]] + 1)
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[-1][-1] if dp[-1][-1] != INF else -1


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
