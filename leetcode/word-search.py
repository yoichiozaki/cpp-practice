class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        H = len(board)
        W = len(board[0])
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        def dfs(h, w, word):
            if len(word) == 0:
                return True
            if h < 0 or H <= h or w < 0 or W <= w or word[0] != board[h][w]:
                return False

            tmp = board[h][w]
            board[h][w] = None
            ret = any([dfs(h + dh, w + dw, word[1:]) for (dh, dw) in dirs])
            board[h][w] = tmp
            return ret

        for h in range(H):
            for w in range(W):
                if dfs(h, w, word):
                    return True
        return False