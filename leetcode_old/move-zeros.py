class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        last_non_zero_at = 0
        for i in range(0, len(nums), 1):
            if nums[i] != 0:
                nums[last_non_zero_at], nums[i] = nums[i], nums[last_non_zero_at]
                last_non_zero_at += 1
