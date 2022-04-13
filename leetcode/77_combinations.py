class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        def rec(nums, sofar):
            if len(sofar) == k:
                ans.append(sofar)
                return
            for i in range(len(nums)):
                rec(nums[i+1:], sofar + [nums[i]])
        rec([i + 1 for i in range(n)], [])
        return ans