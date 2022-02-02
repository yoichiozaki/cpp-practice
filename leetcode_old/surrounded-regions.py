class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        H = len(board)
        W = len(board[0])

        save = [ij for k in range(H + W)
                for ij in [(0, k), (H-1, k), (k, 0), (k, W-1)]]
        while len(save) != 0:
            (i, j) = save.pop()
            if 0 <= i < H and 0 <= j < W and board[i][j] == "O":
                board[i][j] = "S"
                save += [(i, j-1), (i, j+1), (i-1, j), (i+1, j)]

        board[:] = [["XO"[ch == "S"] for ch in row] for row in board]
