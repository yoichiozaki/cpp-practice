class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == -2**31 and divisor == -1:
            return 2**31 - 1
        dvd = abs(dividend)
        dvs = abs(divisor)
        ans = 0
        sign = +1
        if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
            sign = -1
        while dvd >= dvs:
            tmp = dvs
            m = 1
            while tmp << 1 <= dvd:
                tmp <<= 1
                m <<= 1
            dvd -= tmp
            ans += m
        return sign * ans

