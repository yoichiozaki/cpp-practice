# 花壇の花が咲ききるまで待ってしまえば必ず花束は作れる -> 花束が作れるかは待つ日数に対して単調性がある -> 二分探索
class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if len(bloomDay) < m * k:
            return -1
        ng = 0
        ok = max(bloomDay)
        def is_ok(mid):
            pickable = [day <= mid for day in bloomDay]
            flower = 0
            bouquet = 0
            for p in pickable:
                if p:
                    flower += 1
                    if flower == k:
                        bouquet += 1
                        flower = 0
                        if bouquet == m:
                            return True
                else:
                    flower = 0
            return False
        while 1 < abs(ok - ng):
            mid = (ok + ng) // 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok