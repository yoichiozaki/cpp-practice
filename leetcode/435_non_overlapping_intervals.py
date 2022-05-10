# 重ならないようにできるだけ多くの期間を採用したい（＝不採用期間を最小にしたい）ので、できるだけ終わりが早くやってくる期間を貪欲に採用する
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        end = float("-inf")
        cnt = 0
        for s, e in sorted(intervals, key=lambda x: x[1]):
            if end <= s:
                end = e
            else:
                cnt += 1
        return cnt