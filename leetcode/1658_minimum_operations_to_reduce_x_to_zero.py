class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        left = 0
        right = 0
        accum = sum(nums)
        ans = float("inf")
        N = len(nums)
        while left <= right:
            if accum >= x:
                if accum == x:
                    ans = min(ans, N - (right - left))
                if right < N:
                    accum -= nums[right]
                    right += 1
                else:
                    break
            else:
                accum += nums[left]
                left += 1
        return ans if ans != float("inf") else -1