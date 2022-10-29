# どの数字にそろえるかでかかるコストは凸関数なので二分探索
class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        def f(x):
            return sum(abs(num - x) for num in nums)
        left = min(nums)
        right = max(nums)
        ans = f(left)
        while left < right:
            mid = (left + right) // 2
            c0 = f(mid)
            c1 = f(mid + 1)
            ans = min(c0, c1)
            if c0 < c1:
                right = mid
            else:
                left = mid + 1
        return ans