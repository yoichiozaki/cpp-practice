# リストを連結リストとみなすと，ダブリがあるところでループになってる
# Time: O(n), Space: O(1)
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        faster = nums[0]
        slower = nums[0]

        while True:
            faster = nums[nums[faster]]
            slower = nums[slower]
            if faster == slower:
                break

        slower = nums[0]
        while slower != faster:
            faster = nums[faster]
            slower = nums[slower]

        return slower


# Time: O(n log n), Space: O(1) or O(n) depending on used sorting algorithm
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1]:
                return nums[i]

# Time: O(n), Space: O(n)


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        seen = set()
        for num in nums:
            if num in seen:
                return num
            seen.add(num)
