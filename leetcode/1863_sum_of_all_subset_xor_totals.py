class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
            ans |= num
        return ans * (1 << (len(nums) - 1))
