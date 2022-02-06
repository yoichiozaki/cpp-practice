# Time: O(n log n)
class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        ans = []
        for i, num in enumerate(nums):
            if num == target:
                ans.append(i)
        return ans


# targetより大きい数字については整列されている必要はない
# Time: O(n), 数え上げソートの考え方の応用
class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        cnt = 0
        less = 0
        for num in nums:
            if num == target:
                cnt += 1
            elif num < target:
                less += 1
        ans = []
        for i in range(cnt):
            ans.append(less + i)
        return ans
