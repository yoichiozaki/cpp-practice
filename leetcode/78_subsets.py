class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        N = len(nums)
        def rec(pos, sofar):
            if pos == N:
                ans.append(sofar)
                return
            rec(pos + 1, sofar)
            rec(pos + 1, sofar + [nums[pos]])
        rec(0, [])
        return ans