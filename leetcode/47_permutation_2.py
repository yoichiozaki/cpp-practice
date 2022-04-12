# 同じ数字はスキップするという動きを、配列のソート + 添え字の移動で実現する
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        def rec(nums, sofar):
            if len(nums) == 0:
                ans.append(sofar)
                return
            for i in range(len(nums)):
                if i < len(nums) - 1 and nums[i] == nums[i + 1]:
                    continue
                rec(nums[:i] + nums[i + 1:], sofar + [nums[i]])
        rec(nums, [])
        return ans