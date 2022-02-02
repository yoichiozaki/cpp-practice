class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        s = newInterval[0]
        e = newInterval[1]

        lhs = [interval for interval in intervals if interval[1] < s]
        rhs = [interval for interval in intervals if e < interval[0]]

        if lhs + rhs != intervals:
            s = min(s, intervals[len(lhs)][0])
            e = max(e, intervals[-len(rhs)-1][1])

        return lhs + [[s, e]] + rhs
