class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # dp[i][j] = (0, 0)-(i, j)の最小和
        # dp[i+1][j+1] = min(dp[i+1][j], dp[i][j+1]) + grid[i+1][j+1]

        h = len(grid)
        w = len(grid[0])
        dp = [[float("inf") for _ in range(w)] for _ in range(h)]
        dp[0][0] = grid[0][0]

        for i in range(1, h):
            dp[i][0] = dp[i-1][0] + grid[i][0]

        for j in range(1, w):
            dp[0][j] = dp[0][j-1] + grid[0][j]

        for i in range(1, h):
            for j in range(1, w):
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j]

        return dp[-1][-1]
