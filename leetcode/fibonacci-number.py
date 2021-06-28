class Solution:
    def fib(self, n: int) -> int:
        if n == 0 or n == 1:
            return n
        memo = [None for _ in range(n + 1)]
        memo[0] = 0
        memo[1] = 1

        def _fib(n):
            if n == 0 or n == 1:
                return memo[n]
            memo[n] = _fib(n - 1) + _fib(n - 2)
            return memo[n]

        return _fib(n)
