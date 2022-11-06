# BruteForce
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        while a * a <= c:
            b = 0
            while b * b <= c:
                if a * a + b * b == c:
                    return True
                b += 1
            a += 1
        return False


# 要するに片方を決め打ちした時に、相方が平方数であるかを効率よく計算できれば良い -> 二分探索で平方数であるかを判定できる
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        def is_square(num):
            left = 0
            right = num
            while left <= right:
                mid = (left + right) // 2
                if mid * mid == num:
                    return True
                if num < mid * mid:
                    right = mid - 1
                else:
                    left = mid + 1
            return False

        a = 0
        while a * a <= c:
            remain = c - a * a
            if is_square(remain):
                return True
            a += 1
        return False


# a <= b を仮定すれば 2pointers 的にも書ける？
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        b = int(math.sqrt(c))
        while a <= b:
            s = a * a + b * b
            if s == c:
                return True
            elif c < s:
                b -= 1
            else:
                a += 1
        return False


# sqrtの結果が整数になるかを型変換して確認する方法（邪道な気がする）
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        for a in range(int(math.sqrt(c)) + 1):
            b = math.sqrt(c - a * a)
            if b == int(b):
                return True
        return False