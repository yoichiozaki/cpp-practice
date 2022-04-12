class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        dirs = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
        H = len(board)
        W = len(board[0])
        h = click[0]
        w = click[1]
        if board[h][w] == "M":
            board[h][w] = "X"
            return board
        elif board[h][w] == "E":
            bombs = 0
            for (dh, dw) in dirs:
                nh = h + dh
                nw = w + dw
                if not (0 <= nh < H and 0 <= nw < W):
                    continue
                if board[nh][nw] == "M":
                    bombs += 1
            if bombs == 0:
                board[h][w] = "B"
                for (dh, dw) in dirs:
                    nh = h + dh
                    nw = w + dw
                    if not (0 <= nh < H and 0 <= nw < W):
                        continue
                    board = self.updateBoard(board, [nh, nw])
            else:
                board[h][w] = str(bombs)
        return board
            