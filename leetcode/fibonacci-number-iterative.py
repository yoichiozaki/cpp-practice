class Solution:
    def fib(self, n: int) -> int:
        if n <= 1:
            return n
        if n == 2:
            return 1

        prev1 = 1
        prev2 = 1
        current = 0

        for i in range(3, n + 1):
            current = prev1 + prev2
            prev1 = prev2
            prev2 = current
        return current
