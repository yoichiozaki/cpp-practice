class Solution:
    def countEven(self, num: int) -> int:
        def digit_sum(num):
            ret = 0
            while num != 0:
                ret += num % 10
                num = num // 10
            return ret
        ans = 0
        for i in range(1, num + 1):
            if digit_sum(i) % 2 == 0:
                ans += 1
        return ans