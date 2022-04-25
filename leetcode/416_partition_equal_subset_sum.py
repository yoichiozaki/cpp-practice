class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        if s % 2 == 1:
            return False
        
        target = s // 2
        
        # dp[i][j]: i番目までの数字を使って合計jを達成できるか
        dp = [[False for _ in range(target + 1)] for _ in range(len(nums) + 1)]
        
        # どの数字も使わないで合計0を達成は可能
        dp[0][0] = True
        
        # i番目までの数字を使って合計0を達成は可能
        for i in range(1, len(nums) + 1):
            dp[i][0] = True
        
        # どの数字も使わないで合計jを達成は不可能
        for j in range(1, target + 1):
            dp[0][j] = False
            
        for i in range(1, len(nums) + 1):
            for j in range(1, target + 1):
                dp[i][j] = dp[i-1][j]
                if 0 <= j-nums[i-1]:
                    dp[i][j] |= dp[i-1][j-nums[i-1]]
        
        return dp[-1][-1]