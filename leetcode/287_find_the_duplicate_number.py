# Time: O(n log n)
# Space: O(n) or O(log n) depending on algorithms
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i-1] == nums[i]:
                return nums[i]


# Time: O(n)
# Space: O(n)
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        seen = set()
        for num in nums:
            if num in seen:
                return num
            seen.add(num)


# Time: O(n)
# Space: O(1)
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for num in nums:
            idx = abs(num)
            if nums[idx] < 0:
                return idx
            nums[idx] *= -1


# Time: O(n) ... numsを1つずつ歩いていくから
# Space: O(n) ... numsの要素分再帰関数が呼ばれる
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        def walk(nums, curr):
            if curr == nums[curr]:
                return curr
            nxt = nums[curr]
            nums[curr] = curr
            return walk(nums, nxt)
        return walk(nums, 0)


# Time: O(n)
# Space: O(1)
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        while nums[0] != nums[nums[0]]:
            nums[nums[0]], nums[0] = nums[0], nums[nums[0]]
        return nums[0]


# 2-pointers ... 実質やってることは同じ
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
        while faster != slower:
            slower = nums[slower]
            faster = nums[faster]
        return slower
