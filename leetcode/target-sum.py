# DFS
# Time: O(2 ^ N), Space: O(N)
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        ans = 0

        def rec(i, sofar):
            nonlocal ans
            if i == len(nums):
                if sofar == target:
                    ans += 1
            else:
                rec(i + 1, sofar + nums[i])
                rec(i + 1, sofar - nums[i])
        rec(0, 0)
        return ans


# DFS
# Time: O(2 ^ N), Space: O(N)
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        def rec(i, sofar):
            if i == len(nums):
                if sofar == target:
                    return 1
                else:
                    return 0
            else:
                return rec(i + 1, sofar + nums[i]) + rec(i + 1, sofar - nums[i])

        return rec(0, 0)


# bit全探索
# Time: O(2 ^ N), Space: O(1)
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        ans = 0
        for i in range(1 << len(nums)):
            tmp = 0
            for idx, num in enumerate(nums):
                if i & (1 << idx):
                    tmp -= num
                else:
                    tmp += num
            if tmp == target:
                ans += 1
        return ans


# DP
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        def rec(i, sofar, memo):
            if (i, sofar) in memo:
                return memo[(i, sofar)]

            if i == -1:
                if sofar == target:
                    return 1
                else:
                    return 0
            else:
                positive = rec(i - 1, sofar + nums[i], memo)
                negative = rec(i - 1, sofar - nums[i], memo)
                memo[(i, sofar)] = positive + negative
                return memo[(i, sofar)]

        memo = dict()
        return rec(len(nums) - 1, 0, memo)
