class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # dp[i]: nums[i]が右端要素となるような連続する部分配列の和の最大値
        # dp[i+1] = max(dp[i] + nums[i], nums[i])
        dp = [float("-inf")] * len(nums)
        dp[0] = nums[0]
        for i in range(len(nums) - 1):
            dp[i + 1] = max(dp[i] + nums[i + 1], nums[i + 1])
        return max(dp)
