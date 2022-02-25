class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def is_ok(mid):
            return target <= nums[mid]

        ng = -1
        ok = len(nums)

        while 1 < abs(ng - ok):
            mid = (ng + ok) >> 1
            if is_ok(mid):
                ok = mid
            else:
                ng = mid

        return ok if 0 <= ok < len(nums) and nums[ok] == target else -1
