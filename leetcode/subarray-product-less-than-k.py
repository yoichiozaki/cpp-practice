# 右端を固定して左端を回す数え方
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0

        product = 1
        left = 0
        ans = 0
        for right, num in enumerate(nums):
            product *= num
            while k <= product:
                product /= nums[left]
                left += 1
            ans += right - left + 1
        return ans
