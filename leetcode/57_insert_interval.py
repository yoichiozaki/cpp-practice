class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        s = newInterval[0]
        e = newInterval[1]
        left = [interval for interval in intervals if interval[1] < s] # newIntervalと被らない左側
        right = [interval for interval in intervals if e < interval[0]] # newIntervalと被らない右側
        if left + right != intervals:
            s = min(s, intervals[len(left)][0])
            e = max(e, intervals[-len(right)-1][1])
        return left + [[s, e]] + right