class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.matrix = matrix
        H = len(matrix)
        W = len(matrix[0])
        accum = [[0 for _ in range(W + 1)] for _ in range(H + 1)]
        for h in range(0, H):
            for w in range(0, W):
                accum[h + 1][w + 1] = accum[h][w + 1] + \
                    accum[h + 1][w] - accum[h][w] + matrix[h][w]
        self.accum = accum

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        row2 += 1
        col2 += 1
        return self.accum[row2][col2] - self.accum[row2][col1] - self.accum[row1][col2] + self.accum[row1][col1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
