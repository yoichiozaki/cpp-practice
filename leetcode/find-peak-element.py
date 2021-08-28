# Sequential search
# Time: O(n)
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            if nums[i-1] > nums[i]:
                return i - 1
        return len(nums) - 1


# Binary search
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        # search in nums[left:right+1]
        def binary_search(left, right):
            if left == right:
                return left
            else:
                mid1 = (left + right) // 2
                mid2 = mid1 + 1
                if nums[mid1] > nums[mid2]:
                    return binary_search(left, mid1)
                else:
                    return binary_search(mid2, right)

        return binary_search(0, len(nums) - 1)


# Binary search
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1

        while left < right:
            mid1 = (left + right) // 2
            mid2 = mid1 + 1
            if nums[mid1] < nums[mid2]:
                left = mid2
            else:
                right = mid1
        return left
