class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        # dp[i]: 和がiになる組み合わせの場合の数
        nums = sorted(nums)
        dp = [1] + [0 for _ in range(target)]
        for i in range(target + 1):
            for num in nums:
                if i < num:
                    continue
                if i == num:
                    dp[i] += 1
                if i > num:
                    dp[i] += dp[i - num]
        return dp[target]

# follow-up question: numsに負の数が許される場合は？
