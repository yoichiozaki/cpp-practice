# すぐに思いつきたい再帰な解法
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        if target == 0:
            return 1
        ans = 0
        for num in nums:
            if num <= target:
                ans += self.combinationSum4(nums, target - num)
        return ans


# トップダウンな解法：メモ化
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        memo = [1] + [-1 for _ in range(target)]

        def rec(nums, target):
            if memo[target] != -1:
                return memo[target]
            ans = 0
            for num in nums:
                if num <= target:
                    ans += rec(nums, target - num)
            memo[target] = ans
            return ans
        return rec(nums, target)


# ボトムアップな解法
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

# follow-up question: coin change問題との類似性
