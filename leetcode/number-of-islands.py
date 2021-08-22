# DFS in recursion
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if len(grid) == 0:
            return 0

        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        H = len(grid)
        W = len(grid[0])

        has_visited = set()

        def dfs(h, w):
            has_visited.add((h, w))
            for (dh, dw) in dirs:
                nh = h + dh
                nw = w + dw
                if 0 <= nh < H and 0 <= nw < W and grid[nh][nw] == "1" and (nh, nw) not in has_visited:
                    dfs(nh, nw)

        ans = 0

        for h in range(H):
            for w in range(W):
                if (h, w) not in has_visited and grid[h][w] == "1":
                    dfs(h, w)
                    ans += 1
        return ans


# DFS w/ stack
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        H = len(grid)
        W = len(grid[0])
        has_visited = set()
        suspended = list()

        ans = 0

        for h in range(H):
            for w in range(W):
                if (h, w) in has_visited or grid[h][w] == "0":
                    continue
                has_visited.add((h, w))
                suspended.append((h, w))
                ans += 1
                while len(suspended) != 0:
                    (_h, _w) = suspended.pop()
                    for (dh, dw) in dirs:
                        next_h = _h + dh
                        next_w = _w + dw
                        if 0 <= next_h < H and 0 <= next_w < W and grid[next_h][next_w] == "1" and (next_h, next_w) not in has_visited:
                            has_visited.add((next_h, next_w))
                            suspended.append((next_h, next_w))
        return ans


# BFS w/ queue
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        H = len(grid)
        W = len(grid[0])
        has_visited = set()
        suspended = list()

        ans = 0

        for h in range(H):
            for w in range(W):
                if (h, w) in has_visited or grid[h][w] == "0":
                    continue
                has_visited.add((h, w))
                suspended.append((h, w))
                ans += 1
                while len(suspended) != 0:
                    (_h, _w) = suspended.pop(0)
                    for (dh, dw) in dirs:
                        next_h = _h + dh
                        next_w = _w + dw
                        if 0 <= next_h < H and 0 <= next_w < W and grid[next_h][next_w] == "1" and (next_h, next_w) not in has_visited:
                            has_visited.add((next_h, next_w))
                            suspended.append((next_h, next_w))
        return ans
