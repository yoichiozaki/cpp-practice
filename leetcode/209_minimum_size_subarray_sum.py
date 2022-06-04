# 尺取り法（英語ではtwo pointers）
# Time: O(N), Space: O(1)
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans = float("inf")
        left = 0
        accum = 0
        for right in range(len(nums)):
            accum += nums[right]
            while target <= accum:
                ans = min(ans, right - left + 1)
                accum -= nums[left]
                left += 1
        return ans if ans != float("inf") else 0


# 連続する部分配列の和 -> 累積和
# Time: O(N log N), Space: O(N)
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        accum = [0 for _ in range(n + 1)]
        for i in range(1, n + 1):
            accum[i] = accum[i - 1] + nums[i - 1]
        ans = float("inf")
        for i in range(1, n + 1):
            want = target + accum[i - 1]
            bound = bisect_left(accum, want)
            if bound != len(accum):
                ans = min(ans, bound - i + 1)
        return ans if ans != float("inf") else 0