class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans = float("inf")
        left = 0
        accum = 0
        for right in range(len(nums)):
            accum += nums[right]
            while target <= accum:
                ans = min(ans, right - left + 1)
                accum -= nums[left]
                left += 1
        return ans if ans != float("inf") else 0
