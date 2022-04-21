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