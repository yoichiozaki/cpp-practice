class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])

        for i in range(m):
            for j in range(n):
                live_neighbors = 0
                for x in range(max(0, i - 1), min(i + 2, m)):
                    for y in range(max(0, j - 1), min(j + 2, n)):
                        if (x, y) != (i, j):
                            live_neighbors += (board[x][y] % 2)

                if board[i][j] == 1 and (live_neighbors < 2 or live_neighbors > 3):
                    board[i][j] = -1
                elif board[i][j] == 0 and live_neighbors == 3:
                    board[i][j] = 2

        for i in range(m):
            for j in range(n):
                if board[i][j] == -1:
                    board[i][j] = 0
                elif board[i][j] == 2:
                    board[i][j] = 1


# 現世代で生きていて次世代で死ぬマス -> -1
# 現世代で死んでいて次世代で生きるマス -> 2
# とすれば 2 で割ったあまりで現時点での生死がわかるし状態も表現できる