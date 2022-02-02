class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ret = []

        def rec(nums, remain, sofar):
            if remain < 0:
                return
            if remain == 0 and len(sofar) == k:
                ret.append(sofar)
                return
            for i in range(len(nums)):
                rec(nums[i+1:], remain - nums[i], sofar + [nums[i]])
        rec([i for i in range(1, 10)], n, [])
        return ret
