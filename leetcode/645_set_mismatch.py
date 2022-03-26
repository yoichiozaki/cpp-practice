# Time: O(n^2)
# Space: O(1)
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        dup = -1
        missing = -1
        N = len(nums)
        for i in range(1, N+1, 1):
            cnt = 0
            for j in range(N):
                if i == nums[j]:
                    cnt += 1
            if cnt == 2:
                dup = i
            if cnt == 0:
                missing = i
            if dup != -1 and missing != -1:
                break
        return [dup, missing]


# Time: O(n log n)
# Space: O(n) or O(log n)
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        nums.sort()
        dup = -1
        missing = -1
        for i in range(1, len(nums), 1):
            if nums[i] == nums[i-1]:
                dup = nums[i]
            if nums[i-1] + 1 < nums[i]:
                missing = nums[i-1] + 1
        return [dup, len(nums) if nums[-1] != len(nums) else missing]


# Time: O(n)
# Space: O(n)
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        cnt = dict()
        dup = -1
        missing = -1
        for num in nums:
            if num not in cnt:
                cnt[num] = 1
            else:
                cnt[num] += 1
        for num in range(len(nums)):
            if num in cnt:
                if cnt[num] == 2:
                    dup = num
            else:
                missing = num
        return [dup, missing]


# Time: O(n)
# Space: O(1)
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        dup = -1
        missing = 1
        for num in nums:
            if nums[abs(num) - 1] < 0:
                dup = abs(num)
            else:
                nums[abs(num) - 1] *= -1
        for i in range(1, len(nums), 1):
            if 0 < nums[i]:
                missing = i + 1
        return [dup, missing]
