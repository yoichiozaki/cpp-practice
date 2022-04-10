# 基本的な考え方：領域内にいるか考えずに移動しまくって、その位置が領域内なら答えとして取っておく
# スパイラルに移動するのを向きと移動量で書きだすと、右に1、下に1、左に2、上に2、右に3、下に3、...となっているのでこれをそのまま作り出す
class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        result = []
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        d = 0 # right
        row = rStart
        col = cStart
        n = 0
        while len(result) < rows * cols:
            for _ in range(n // 2 + 1):
                if 0 <= row < rows and 0 <= col < cols:
                    result.append([row, col])
                row += dirs[d][0]
                col += dirs[d][1]
            d = (d + 1) % 4
            n += 1
        return result