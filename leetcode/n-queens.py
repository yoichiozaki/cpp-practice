# backtracing
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        board = [["." for _ in range(n)] for _ in range(n)]
        ret = []

        def conv(board):
            string_board = []
            for board_row in board:
                string_board.append("".join(board_row))
            return string_board

        def is_valid(board, row, col):
            if board[row][col] == "Q":
                return False
            for r in range(n):
                for c in range(n):
                    if board[r][c] == "Q" and (row - r == col - c or row - r == -(col - c) or row == r or col == c):
                        return False
            return True

        def solve(board, col):
            if col == n:
                ret.append(conv(board))
                return

            for row in range(n):
                if is_valid(board, row, col):
                    board[row][col] = "Q"
                    solve(board, col + 1)
                    board[row][col] = "."

        solve(board, 0)
        return ret
