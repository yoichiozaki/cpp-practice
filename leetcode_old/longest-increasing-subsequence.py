class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # dp[i]: 長さi+1の増加部分列の終端要素の最小値
        dp = [float("inf")] * len(nums)

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
