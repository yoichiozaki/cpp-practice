class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        start = intervals[0][0]
        end = intervals[0][1]
        intervals = intervals[1:]
        ans = []
        for interval in intervals:
            next_start = interval[0]
            next_end = interval[1]
            if end < next_start:
                ans.append([start, end])
                start = next_start
                end = next_end
            else:
                if end < next_end:
                    end = next_end
        ans.append([start, end])
        return ans