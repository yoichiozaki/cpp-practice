class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # dp[i]: 右端要素がnums[i]であるような部分列の和の最大値
        if len(nums) == 1:
            return nums[0]
        dp = [float("-inf") for _ in range(len(nums))]
        dp[0] = nums[0]
        for i in range(1, len(nums)):
            dp[i] = max(dp[i - 1] + nums[i], nums[i])
        return max(dp)
