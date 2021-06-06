class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ret = []

        def rec(nums, remain, sofar):
            if remain < 0:
                return
            if remain == 0:
                ret.append(sofar)
                return
            for i in range(len(nums)):
                rec(nums[i:], remain - nums[i], sofar + [nums[i]])
        rec(candidates, target, [])
        return ret
