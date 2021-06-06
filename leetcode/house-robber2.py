class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return max(nums)

        def _rob(nums):
            # dp[i]: nums[:i+1]までで盗めるお金の最大値
            if len(nums) < 3:
                return max(nums)
            dp = [0] * len(nums)
            dp[0] = nums[0]
            dp[1] = max(nums[0], nums[1])
            for i in range(2, len(nums)):
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
            return dp[len(nums) - 1]
        return max(_rob(nums[1:]), _rob(nums[:len(nums) - 1]))
