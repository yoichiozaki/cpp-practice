# backtracing
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        def is_valid(board, row, col, num):

            def is_safe_row(board, row, num):
                for col in range(len(board[0])):
                    if board[row][col] == num:
                        return False
                return True

            def is_safe_col(board, col, num):
                for row in range(len(board)):
                    if board[row][col] == num:
                        return False
                return True

            box_row = row - row % 3
            box_col = col - col % 3

            def is_safe_box(board, box_row, box_col, num):
                for row in range(box_row, box_row + 3):
                    for col in range(box_col, box_col + 3):
                        if board[row][col] == num:
                            return False
                return True

            return is_safe_row(board, row, num) and is_safe_col(board, col, num) and is_safe_box(board, box_row, box_col, num)

        def solve(board):
            for row in range(len(board)):
                for col in range(len(board[0])):
                    if board[row][col] == ".":
                        for num in ("1", "2", "3", "4", "5", "6", "7", "8", "9"):
                            if is_valid(board, row, col, num):
                                board[row][col] = num
                                if solve(board):
                                    return True
                                else:
                                    board[row][col] = "."
                        return False
            return True

        if board is None or len(board) == 0:
            return
        solve(board)
