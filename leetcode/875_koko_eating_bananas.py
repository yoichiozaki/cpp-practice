class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def is_ok(speed):
            return sum(-(-pile // speed) for pile in piles) <= h
        
        ok = max(piles) + 1
        ng = 0
        while abs(ok - ng) > 1:
            mid = (ok + ng) // 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok