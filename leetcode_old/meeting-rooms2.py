# Definition for an interval
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        intervals.sort(key=lambda x: x.start)
        heap = []
        for mtg in intervals:
            if len(heap) != 0 and heap[0] <= mtg.start:
                heapq.heappop(heap)
                heapq.heappush(heap, mtg.end)
            else:
                heapq.heappush(heap, mtg.end)
        return len(heap)
