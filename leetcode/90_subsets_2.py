# 同じ数字を飛ばせばいい。ソートしておけば添え字を進めるだけで同じ数字を飛ばすことになる。
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        N = len(nums)
        def rec(pos, sofar):
            if pos == N:
                ans.append(sofar)
                return
            rec(pos + 1, sofar + [nums[pos]])
            while pos < N - 1 and nums[pos] == nums[pos + 1]:
                pos += 1
            rec(pos + 1, sofar)
        rec(0, [])
        return ans