class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        index, smallest = -1, math.inf
        for i, (x_, y_) in enumerate(points):
            dx, dy = x - x_, y - y_
            if dx * dy == 0 and abs(dx + dy) < smallest:
                smallest = abs(dx + dy)
                index = i
        return index
