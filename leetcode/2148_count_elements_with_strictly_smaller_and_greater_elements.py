class Solution:
    def countElements(self, nums: List[int]) -> int:
        max_num = max(nums)
        min_num = min(nums)
        ans = 0
        for num in nums:
            if min_num < num < max_num:
                ans += 1
        return ans
