# bluce-force
# Time: O(n^3) (for, while, current + 1 in nums)
# Space: O(1)
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        longest = 0
        for num in nums:
            current = num
            current_length = 1
            while current + 1 in nums:
                current += 1
                current_length += 1
            longest = max(longest, current_length)
        return longest


# sort
# Time: O(n log n)
# Space: O(n) or O(1)
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        nums.sort()
        longest = 1
        current_length = 1
        for i in range(1, len(nums)):
            if nums[i-1] != nums[i]:
                if nums[i-1] + 1 == nums[i]:
                    current_length += 1
                else:
                    longest = max(longest, current_length)
                    current_length = 1
        return max(longest, current_length)


# set
# Time: O(n)
# Space: O(n)
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        longest = 0

        for num in nums:
            if num - 1 not in nums:
                current = num
                current_length = 1

                while current + 1 in nums:
                    current += 1
                    current_length += 1

                longest = max(longest, current_length)
        return longest
