# 容積無限大なら一日で運べるし、容積が小さすぎるとそもそも運べない -> 容積に対して運べるかは単調性がある -> 二分探索
class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        ng = max(weights) - 1
        ok = sum(weights)
        def is_ok(mid):
            loaded = 0
            elapsed = 1
            for weight in weights:
                loaded += weight
                if mid < loaded:
                    elapsed += 1
                    loaded = weight
            return elapsed <= days
        while 1 < abs(ok - ng):
            mid = (ok + ng) // 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok