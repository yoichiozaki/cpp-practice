class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
            last_d = 0
            d = 2
            while d * d <= num:
                if num % d == 0:
                    if last_d == 0:  # 初回更新
                        last_d = d
                    else:
                        last_d = 0
                        break
                d += 1
            if last_d != 0 and last_d * last_d != num:
                ans += (1 + last_d + num // last_d + num)
        return ans
