# ある値xにそろえるときのコストは、xに対して凸関数になっていて、どこかで最小になる。二分探索。
class Solution:
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        def f(x):
            return sum(abs(num - x) * c for num, c in zip(nums, cost))
        
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