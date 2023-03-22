class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        def is_valid(board, row, col):
            def is_ok_col(row, col):
                for c in range(len(board[0])):
                    if c == col:
                        continue
                    if board[row][c] == board[row][col]:
                        return False
                return True
        
        
            def is_ok_row(row, col):
                for r in range(len(board)):
                    if r == row:
                        continue
                    if board[r][col] == board[row][col]:
                        return False
                return True
            
            
            def is_ok_box(row, col):
                box_row = row - row % 3
                box_col = col - col % 3
                for r in range(box_row, box_row + 3):
                    for c in range(box_col, box_col + 3):
                        if r == row and c == col:
                            continue
                        if board[r][c] == board[row][col]:
                            return False
                return True

            return is_ok_row(row, col) and is_ok_col(row, col) and is_ok_box(row, col)
        
        
        if board is None or len(board) == 0:
            return False
        
        for row in range(len(board)):
            for col in range(len(board[0])):
                if board[row][col] != ".":
                    if not is_valid(board, row, col):
                        return False
        return True