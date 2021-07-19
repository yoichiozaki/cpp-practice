class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ret = []

        def rec(nums, sofar):
            if len(nums) == 0:
                ret.append(sofar)
                return
            for i in range(len(nums)):
                rec(nums[:i] + nums[i+1:], sofar + [nums[i]])
        rec(nums, [])
        return ret
