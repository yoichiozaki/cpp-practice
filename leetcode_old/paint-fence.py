class Solution:
    def numWays(self, n: int, k: int) -> int:
        if n == 1:
            return k
        if n == 2:
            return k ** 2
        # dp[i]: 左からi番目までの柱の塗り分け方
        dp = [0, k, k ** 2]
        for i in range(2, n):
            dp += [(dp[-2] + dp[-1]) * (k - 1)]
        return dp[n]
