# O(n)
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        first = float("-inf")
        second = float("-inf")
        for num in nums:
            if first < num:
                second = first
                first = num
            elif second < num:
                second = num
        return (first - 1) * (second - 1)

# O(n log n)


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nums.sort()
        return (nums[-1]-1) * (nums[-2]-1)
