class Solution:
    def trailingZeroes(self, n: int) -> int:
        base = 5
        ans = 0
        while base <= n:
            ans += n // base
            base *= 5
        return ans