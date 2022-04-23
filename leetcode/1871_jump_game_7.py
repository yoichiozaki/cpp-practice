class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        dp = [c == '0' for c in s]
        pre = 0
        for i in range(1, len(s)):
            if minJump <= i: 
                pre += dp[i - minJump]
            if maxJump < i:
                pre -= dp[i - maxJump - 1]
            dp[i] &= pre > 0
        return dp[-1]