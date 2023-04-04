class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        if sum(candies) < k:
            return 0

        def is_ok(pile):
            return sum(candy // pile for candy in candies) >= k
        ok = 1
        ng = max(candies) + 1
        while abs(ok - ng) > 1:
            mid = (ok + ng)// 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok