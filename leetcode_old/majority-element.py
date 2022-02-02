# Time: O(n^2), Space: O(1)
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        majority_count = len(nums) // 2
        for num in nums:
            count = 0
            for ele in nums:
                if ele == num:
                    count += 1
            if majority_count < count:
                return num
        return -1


# Time: O(n), Space: O(n)
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d = {}
        for n in nums:
            if n not in d.keys():
                d[n] = 1
            else:
                d[n] += 1
        return max(d, key=d.get)


# Time: O(n log n), Space: O(1) or O(n)
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        return nums[len(nums) // 2]


# Time: O(n), Space: O(1)
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate
