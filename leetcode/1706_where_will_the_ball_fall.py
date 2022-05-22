class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        H = len(grid)
        W = len(grid[0])
        
        def drop(col):
            for row in range(H):
                next_col = col + grid[row][col]
                if not (0 <= next_col < W):
                    return -1
                if grid[row][next_col] != grid[row][col]:
                    return -1
                col = next_col
            return col
        return map(drop, range(W))
