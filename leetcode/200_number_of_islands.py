class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        H = len(grid)
        W = len(grid[0])
        has_visited = set()
        def dfs(h, w):
            has_visited.add((h, w))
            for (dh, dw) in dirs:
                nh = h + dh
                nw = w + dw
                if not (0 <= nh < H and 0 <= nw < W):
                    continue
                if (nh, nw) in has_visited:
                    continue
                if grid[nh][nw] == "0":
                    continue
                dfs(nh, nw)
        ans = 0
        for h in range(H):
            for w in range(W):
                if (h, w) not in has_visited and grid[h][w] == "1":
                    ans += 1
                    dfs(h, w)
        return ans