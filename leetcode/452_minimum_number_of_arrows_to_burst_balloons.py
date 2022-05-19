class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        end = float("-inf")
        cnt = 0
        for s, e in sorted(points, key=lambda p: p[1]):
            if end < s:
                cnt += 1
                end = e
        return cnt