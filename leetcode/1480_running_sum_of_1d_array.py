class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        N = len(nums)
        ans = [0 for _ in range(N)]
        ans[0] = nums[0]
        for i in range(1, N, 1):
            ans[i] = ans[i-1] + nums[i]
        return ans
