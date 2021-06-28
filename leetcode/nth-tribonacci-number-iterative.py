class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 1

        prev3 = 0
        prev2 = 1
        prev1 = 1
        current = 0

        for _ in range(3, n + 1):
            current = prev1 + prev2 + prev3
            prev3 = prev2
            prev2 = prev1
            prev1 = current

        return current
