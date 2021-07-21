class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        left = start
        right = start
        while 0 <= left or right < len(nums):
            if 0 <= left and nums[left] == target:
                return start - left
            if right < len(nums) and nums[right] == target:
                return right - start
            left -= 1
            right += 1
