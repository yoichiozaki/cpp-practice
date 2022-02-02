class Solution:
    def rob(self, nums: List[int]) -> int:
        # dp[i]: nums[:i+1]での盗めるお金の最大値
        # dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        if len(nums) < 3:
            return max(nums)
        dp = [0] * len(nums)
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        for i in range(2, len(nums)):
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
        return dp[-1]
