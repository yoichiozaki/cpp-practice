class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()
        high = nums[0]
        ans = 0
        for i in range(len(nums)):
            num = nums[i]
            if num < high:
                ans += high - num
                high += 1
            else:
                high = num + 1
        return ans