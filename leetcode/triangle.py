class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle:
            return
        for level in range(len(triangle)-2, -1, -1):
            for pos in range(len(triangle[level])):
                triangle[level][pos] += min(triangle[level+1]
                                            [pos], triangle[level+1][pos+1])
        return triangle[0][0]
