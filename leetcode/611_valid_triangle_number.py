class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        ans = 0
        N = len(nums)
        for i in range(N - 2):
            for j in range(i + 1, N - 1):
                for k in range(j + 1, N):
                    if nums[i] + nums[j] > nums[k] and nums[j] + nums[k] > nums[i] and nums[k] + nums[i] > nums[j]:
                        ans += 1
        return ans


class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        ans = 0
        nums.sort()
        for i in range(len(nums) - 2):
            k = i + 2
            j = i + 1
            while j < len(nums) - 1 and nums[i] != 0:
                while k < len(nums) and nums[i] + nums[j] > nums[k]:
                    k += 1
                ans += k - j - 1
                j += 1
        return ans