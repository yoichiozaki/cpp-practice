class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 1

        memo = [None for _ in range(n + 1)]
        memo[0] = 0
        memo[1] = 1
        memo[2] = 1

        def _tribonacci(n):
            if memo[n] is None:
                memo[n] = _tribonacci(
                    n - 1) + _tribonacci(n - 2) + _tribonacci(n - 3)
            return memo[n]

        return _tribonacci(n)
