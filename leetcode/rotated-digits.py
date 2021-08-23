class Solution:
    def rotatedDigits(self, n: int) -> int:
        dp = [0 for _ in range(n + 1)]
        # dp[i] = 0: 逆さま不可
        #         1: 逆さま可・不変
        #         2: 逆さま可・変
        ans = 0
        for i in range(n + 1):
            if i < 10:
                if i in {0, 1, 8}:
                    dp[i] = 1
                elif i in {2, 5, 6, 9}:
                    dp[i] = 2
                    ans += 1
            else:
                others = dp[i // 10]
                most_right = dp[i % 10]
                if most_right == 1 and others == 1:
                    dp[i] = 1
                elif (most_right == 1 and others == 2) or (most_right == 2 and others == 1) or (most_right == 2 and others == 2):
                    dp[i] = 2
                    ans += 1

        return ans
