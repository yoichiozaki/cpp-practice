class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ret = []

        def rec(nums, pos, remain, sofar):
            if remain < 0:
                return
            if remain == 0:
                ret.append(sofar)
                return
            for i in range(pos, len(nums)):
                if pos < i and nums[i] == nums[i-1]:
                    continue
                rec(nums, i + 1, remain - nums[i], sofar + [nums[i]])

        candidates.sort()
        rec(candidates, 0, target, [])
        return ret
