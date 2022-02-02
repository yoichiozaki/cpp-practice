class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        missing = len(nums)
        for i, num in enumerate(nums):
            missing ^= i ^ num
        return missing


# class Solution:
#     def missingNumber(self, nums: List[int]) -> int:
#         n = len(nums)
#         allsum = (n * (n + 1)) // 2
#         return allsum - sum(nums)
