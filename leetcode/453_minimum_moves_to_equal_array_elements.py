# m回の操作でnumsの要素が全部xにそろったとすると、
# sum(nums) + m * (len(nums) - 1) == len(nums) * x
# xはm回の操作を行った結果なので x == min(nums) + m
# よってsum(nums) + m * len(nums) - m == len(nums) * min(nums) + m * len(nums)
# sum(nums) - m == len(nums) * min(nums)
# m = sum(nums) - len(nums) * min(nums)
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return sum(nums) - len(nums) * min(nums)