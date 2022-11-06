class Solution:
    def makeIntegerBeautiful(self, n: int, target: int) -> int:
        def sum_of_digits(num):
            ret = 0
            while num != 0:
                ret += num % 10
                num = num // 10
            return ret
        ans = 0
        digit = 1
        while digit <= len(str(n)) + 1:
            if sum_of_digits(n + ans) <= target:
                return ans
            else:
                base = 10 ** digit
                ans = base - (n % base)
                digit += 1
        return -1 # never reach here


class Solution:
    def makeIntegerBeautiful(self, n: int, target: int) -> int:
        def sum_of_digits(num):
            ret = 0
            while num != 0:
                ret += num % 10
                num = num // 10
            return ret
        n0 = n
        i = 0
        while sum_of_digits(n) > target:
            n = n // 10 + 1 # ここで桁を落としても各桁の合計を考えるのならばわざわざ n を本当の値で維持しておく必要はなくて桁を落として 0 の部分を無視しても構わない
            i += 1
        return n * (10 ** i) - n0