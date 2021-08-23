class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        ans = [0 for _ in range(len(nums))]
        for i in range(len(nums)):
            ans[0] += nums[i] - nums[0]

        for j in range(1, len(nums)):
            ans[j] = ans[j-1] + (nums[j] - nums[j-1]) * \
                j - (nums[j] - nums[j-1]) * (len(nums) - j)

        return ans
