class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        end = float("-inf")
        cnt = 0
        for s, e in sorted(intervals, key=lambda i: i[1]):
            if end <= s:
                end = e
            else:
                cnt += 1
        return cnt
