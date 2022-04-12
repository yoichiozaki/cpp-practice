# 1個取り出して、1個取り出して、っていうのをそのまま書く
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        N = len(nums)
        def rec(nums, sofar):
            if len(nums) == 0:
                ans.append(sofar)
                return
            for i in range(len(nums)):
                rec(nums[:i] + nums[i+1:], sofar + [nums[i]])
        rec(nums, [])
        return ans
            