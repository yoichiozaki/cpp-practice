class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        def is_ok(mid):
            if mid == len(arr) - 1:
                return True
            return arr[mid] > arr[mid + 1]
        ng = -1
        ok = len(arr)
        while 1 < abs(ng - ok):
            mid = (ng + ok) >> 1
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok
