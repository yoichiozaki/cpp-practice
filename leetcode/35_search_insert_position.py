class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        def is_ok(mid):
            return target <= nums[mid]
        ok = len(nums)
        ng = -1
        while 1 < abs(ok - ng):
            mid = (ok + ng) // 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok