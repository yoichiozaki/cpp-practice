class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1]:
                nums[i] *= 2
                nums[i + 1] = 0
        ans = []
        zeros = 0
        for num in nums:
            if num == 0:
                zeros += 1
            else:
                ans.append(num)
        ans = ans + [0 for _ in range(zeros)]
        return ans