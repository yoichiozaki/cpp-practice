class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        N = len(grid)
        ans = 0
        for i in range(N):
            for j in range(N):
                if grid[i][j] != 0:
                    ans += (grid[i][j] * 4) + 2
                if 1 <= i:
                    ans -= min(grid[i][j], grid[i-1][j]) * 2
                if 1 <= j:
                    ans -= min(grid[i][j], grid[i][j-1]) * 2
        return ans