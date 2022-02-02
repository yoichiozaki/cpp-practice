class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # dp[i]: i支払うために必要な硬貨の組み合わせの場合の数
        dp = [1] + [0 for _ in range(amount)]
        coins = sorted(coins)
        for coin in coins:
            for i in range(amount + 1):
                if i < coin:
                    continue
                if i == coin:
                    dp[i] += 1
                if i > coin:
                    dp[i] += dp[i - coin]
        return dp[amount]
