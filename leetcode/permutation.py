class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []

        def _recurse(nums, sofar):
            if len(nums) == 0:
                ans.append(sofar)
                return
            for i in range(len(nums)):
                _recurse(nums[:i]+nums[i+1:], sofar + [nums[i]])
        _recurse(nums, [])
        return ans
