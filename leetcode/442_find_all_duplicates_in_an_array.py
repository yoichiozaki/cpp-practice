# Time: O(n)
# Space: O(n)
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        ans = []
        for num in cnt.keys():
            if cnt[num] == 2:
                ans.append(num)
        return ans


# Time: O(n)
# Space: O(1)
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ans = []
        for num in nums:
            if nums[abs(num) - 1] < 0:
                ans.append(abs(num))
            else:
                nums[abs(num) - 1] *= -1
        return ans
