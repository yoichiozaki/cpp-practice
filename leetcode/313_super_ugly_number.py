class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        size = len(primes)

        dp = [1]
        candidates = [1 for _ in range(size)]
        index = [0 for _ in range(size)]
        ugly = 1

        for _ in range(1, n):
            for j in range(size):
                if ugly == candidates[j]:
                    candidates[j] = dp[index[j]] * primes[j]
                    index[j] += 1
            ugly = min(candidates)
            dp.append(ugly)
        return dp[-1]
