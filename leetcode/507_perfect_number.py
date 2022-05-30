class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num == 1:
            return False
        def factors(n):
            ret = []
            i = 2
            while i * i <= n:
                if n % i == 0:
                    ret += [i, n / i]
                i += 1
            return ret
        return sum(factors(num)) == num - 1