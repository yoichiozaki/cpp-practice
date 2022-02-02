class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if nums[0] == target:
            return 0

        def is_ok(mid):
            if nums[0] < target:
                return target <= nums[mid] or nums[mid] < nums[0]
            else:
                return target <= nums[mid] and nums[mid] < nums[0]

        ng = -1
        ok = len(nums)
        while 1 < abs(ng - ok):
            mid = (ng + ok) // 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid

        if ok < 0 or len(nums) <= ok or nums[ok] != target:
            return -1
        else:
            return ok
