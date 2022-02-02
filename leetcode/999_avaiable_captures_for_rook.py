# 要するに深さ優先探索
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        x0, y0 = 0, 0
        for i in range(8):
            for j in range(8):
                if board[i][j] == "R":
                    x0 = i
                    y0 = j
        ans = 0
        for (dx, dy) in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
            x = x0 + dx
            y = y0 + dy
            while 0 <= x < 8 and 0 <= y < 8:
                if board[x][y] == "p":
                    ans += 1
                if board[x][y] != ".":
                    break
                x += dx
                y += dy
        return ans
