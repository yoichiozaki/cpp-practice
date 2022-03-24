# Time: O(n^2)
# Space: O(1)
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        for num in nums:
            cnt = sum(1 for ele in nums if ele == num)
            if len(nums) // 2 < cnt:
                return num


# Time: O(n)
# Space: O(n)
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cnts = collections.Counter(nums)
        return max(cnts.keys(), key=cnts.get)


# Time: O(n log n)
# Space: O(1) or O(n) (depending on sorting algorithm)
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        return nums[len(nums) // 2]


# Time: O(n)
# Space: O(1)
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = None
        count = 0
        for num in nums:
            if count == 0:
                candidate = num
            if num == candidate:
                count += 1
            else:
                count -= 1
        return candidate
