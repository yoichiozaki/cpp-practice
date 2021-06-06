class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        def is_ok(mid):
            return target <= nums[mid]

        ng = -1
        ok = len(nums)
        while 1 < abs(ng - ok):
            mid = (ng + ok) // 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok
