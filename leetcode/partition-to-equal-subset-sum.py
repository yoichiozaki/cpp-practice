# brute-force: O(2^N)
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        ans = []
        for bit in range(1 << n):
            sum1 = 0
            sum2 = 0
            for i in range(n):
                if (bit >> i) & 1:
                    sum1 += nums[i]
                else:
                    sum2 += nums[i]
            ans.append(sum1 == sum2)
        return any(ans)


# 01-ナップザック
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        # 合計が奇数ならそもそも無理
        if s & 1 == 1:
            return False

        target = s // 2

        # dp[i][j]: i番目までの数字を使って合計jを達成できるか
        # dp[i][j] = dp[i][j] or dp[i-1][j-nums[i-1]]
        dp = [[False for _ in range(target + 1)] for _ in range(len(nums) + 1)]

        # どの数字も使わずに合計0を達成可能
        dp[0][0] = True

        # i番目までの数字を使って合計0は達成可能
        for i in range(1, len(nums) + 1):
            dp[i][0] = True

        # どの数字も使わずに合計jは達成不可能
        for j in range(1, target + 1):
            dp[0][j] = False

        for i in range(1, len(nums) + 1):
            for j in range(1, target + 1):
                dp[i][j] = dp[i-1][j]
                if 0 <= j-nums[i-1]:
                    dp[i][j] = dp[i][j] or dp[i-1][j-nums[i-1]]

        return dp[len(nums)][target]
