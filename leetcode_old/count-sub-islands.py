class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        H = len(grid2)
        W = len(grid2[0])
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        def dfs(h, w, sofar):
            sofar.add((h, w))
            grid2[h][w] = 2
            for (dh, dw) in dirs:
                nh = h + dh
                nw = w + dw
                if 0 <= nh < H and 0 <= nw < W and grid2[nh][nw] == 1 and (nh, nw) not in sofar:
                    dfs(nh, nw, sofar)
            return sofar

        ans = 0
        for h in range(H):
            for w in range(W):
                if grid2[h][w] == 1:
                    island = list(dfs(h, w, set()))
                    if all([grid1[i][j] == 1 for (i, j) in island]):
                        ans += 1

        return ans
