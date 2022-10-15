class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        ng = 0 # sum(quantities) // n - 1
        ok = max(quantities)
        def is_ok(mid):
            stores = 0
            for quantity in quantities:
                stores += quantity // mid
                if quantity % mid != 0:
                    stores += 1
            return stores <= n
        while 1 < abs(ng - ok):
            mid = (ok + ng) // 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok