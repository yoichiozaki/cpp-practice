class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        left = 0
        ans = 0
        for right in range(len(nums)):
            if nums[right] == 0:
                left = right + 1
            ans = max(ans, right - left + 1)
        return ans