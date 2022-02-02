class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        ret = 0
        anchor_index = 0
        for i in range(len(nums)):
            if 0 < i and nums[i-1] >= nums[i]:
                anchor_index = i  # reset anchor_index
            ret = max(ret, i - anchor_index + 1)
        return ret
