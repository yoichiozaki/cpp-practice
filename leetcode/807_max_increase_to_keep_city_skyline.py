class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        row_limit = [max(height) for height in grid]
        col_limit = [max(height) for height in zip(*grid)]
        return sum(min(row_limit[r], col_limit[c]) - height for r, row in enumerate(grid) for c, height in enumerate(row))
