class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        for (x, y) in points:
            dist = -(x * x + y * y)
            if len(heap) == k:
                heapq.heappushpop(heap, (dist, x, y))
            else:
                heapq.heappush(heap, (dist, x, y))
        return [(x, y) for (_, x, y) in heap]


# k番目以下・k番目以上の要素ときたら「空のheapから初めて長さがk以下になるようにheappush/heappushpop」