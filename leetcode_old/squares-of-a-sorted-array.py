# O(n)
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        ans = collections.deque()
        l, r = 0, len(nums) - 1
        while l <= r:
            left, right = abs(nums[l]), abs(nums[r])
            if right < left:
                ans.appendleft(left ** 2)
                l += 1
            else:
                ans.appendleft(right ** 2)
                r -= 1
        return list(ans)

# O(n log n)


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        nums = sorted(nums, key=lambda x: abs(x))
        return list(map(lambda x: x**2, nums))
