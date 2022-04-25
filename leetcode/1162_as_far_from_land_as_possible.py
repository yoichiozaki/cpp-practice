# TODO: 並列に複数始点BFSを実行するO(n^2)がある


# O(n^3)
# X始点のBFSを「1始点のBFS」をX回でやろうとして時間がかかる
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        H = len(grid)
        W = len(grid[0])
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        def bfs(h, w):
            walk = 0
            suspended = [(h, w)]
            has_visited = set()
            while len(suspended) != 0:
                next_suspended = []
                walk += 1
                for (ch, cw) in suspended:
                    has_visited.add((ch, cw))
                    for (dh, dw) in dirs:
                        nh = ch + dh
                        nw = cw + dw
                        if not (0 <= nh < H and 0 <= nw < W):
                            continue
                        if (nh, nw) in has_visited:
                            continue
                        if grid[nh][nw] == 1:
                            return walk
                        next_suspended.append((nh, nw))
                suspended = next_suspended
            return -1
        max_distance = -1
        for h in range(H):
            for w in range(W):
                if grid[h][w] == 0:
                    distance = bfs(h, w)
                    max_distance = max(max_distance, distance)
        return max_distance