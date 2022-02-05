# 連続する部分列は右端の要素で二通りに分けられる
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # dp[i] = 右端がnums[i]であるような部分列の和の最大値
        N = len(nums)
        if N == 1:
            return nums[0]
        dp = [float("-inf") for _ in range(N)]
        dp[0] = nums[0]
        for i in range(1, N):
            dp[i] = max(dp[i-1] + nums[i], nums[i])
        return max(dp)
