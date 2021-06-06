class Solution:
    def findMin(self, nums: List[int]) -> int:
        def is_ok(mid):
            return nums[mid] < nums[0]
        ng = -1
        ok = len(nums)
        while 1 < abs(ok - ng):
            mid = (ok + ng) // 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return nums[ok] if ok != len(nums) else nums[0]
