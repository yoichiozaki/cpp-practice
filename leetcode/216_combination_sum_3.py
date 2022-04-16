class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        nums = [i for i in range(1, 10)]
        ans = []
        def rec(nums, remain, sofar):
            if len(sofar) > k:
                return
            if remain < 0:
                return
            if remain == 0 and len(sofar) == k:
                ans.append(sofar)
                return
            for i in range(len(nums)):
                rec(nums[i+1:], remain - nums[i], sofar + [nums[i]])
        rec(nums, n, [])
        return ans