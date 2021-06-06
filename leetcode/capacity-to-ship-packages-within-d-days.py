class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        def is_ok(mid):
            elapsed = 1
            loaded = 0
            for weight in weights:
                loaded += weight
                if mid < loaded:
                    elapsed += 1
                    loaded = weight
            return elapsed <= D

        ng = max(weights) - 1  # 常に条件を満たさない
        ok = sum(weights) + 1  # 常に条件を満たす
        while 1 < abs(ng - ok):
            mid = (ng + ok) // 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok
