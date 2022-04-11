class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:        
        if not board:
            return False
        H = len(board)
        W = len(board[0])
        def dfs(h, w, target):
            # target word found!
            if len(target) == 0:
                return True
            # out of field
            if not (0 <= h < H) or not (0 <= w < W):
                return False
            
            if target[0] != board[h][w]:
                return False
            board[h][w] = "#"
            ret = dfs(h, w + 1, target[1:]) or dfs(h + 1, w, target[1:]) or dfs(h, w - 1, target[1:]) or dfs(h - 1, w, target[1:])
            board[h][w] = target[0]
            return ret
        
        for h in range(H):
            for w in range(W):
                if dfs(h, w, word):
                    return True
        return False