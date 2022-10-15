# `x` 個のバッグを `additionalRocks` 個の石で満タンできるか、という問題の答えは `x` について単調 -> 二分探索
class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        N = len(capacity)
        ok = -1
        ng = N + 1
        def is_ok(mid):
            space = [capacity[i] - rocks[i] for i in range(N)]
            space.sort()
            remain = additionalRocks
            for i in range(N):
                remain -= space[i]
                if remain == 0:
                    return mid <= i + 1
                if remain < 0:
                    return mid <= i
            return True
        while 1 < abs(ok - ng):
            mid = (ok + ng) // 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok