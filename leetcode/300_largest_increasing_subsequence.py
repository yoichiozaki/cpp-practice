class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # dp[i]: nums[i]で終わる単調増加部分列の長さの最大値
        dp = [1 for _ in range(len(nums))]
        for i in range(len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)

        
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # dp[i]: 長さi+1の増加部分列の右端の最小値
        # 増加部分列の長さに対して右端の最小値は単調に増加
        dp = [float("inf") for _ in range(len(nums))]
        def binary_search(nums, key):
            ok = len(nums)
            ng = -1
            def is_ok(mid):
                return key <= nums[mid]
            while 1 < abs(ng - ok):
                mid = (ng + ok) // 2
                if is_ok(mid):
                    ok = mid
                else:
                    ng = mid
            return ok
        for num in nums:
            dp[binary_search(dp, num)] = num
        return binary_search(dp, float("inf"))