class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not obstacleGrid:
            return 0
        H = len(obstacleGrid)
        W = len(obstacleGrid[0])

        obstacleGrid[0][0] = 1 - obstacleGrid[0][0]

        for h in range(1, H):
            obstacleGrid[h][0] = obstacleGrid[h-1][0] * \
                (1 - obstacleGrid[h][0])

        for w in range(1, W):
            obstacleGrid[0][w] = obstacleGrid[0][w-1] * \
                (1 - obstacleGrid[0][w])

        for h in range(1, H):
            for w in range(1, W):
                obstacleGrid[h][w] = (
                    obstacleGrid[h-1][w] + obstacleGrid[h][w-1]) * (1 - obstacleGrid[h][w])

        return obstacleGrid[H-1][W-1]
