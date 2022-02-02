# TLE: O(n^2)
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] == nums[j] and j - i <= k:
                    return True
        return False


# AC: O(n)
# 直近の位置を持っていれば十分
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        memo = dict()
        for i, num in enumerate(nums):
            if num in memo:
                if i - memo[num] <= k:
                    return True
            memo[num] = i
        return False
