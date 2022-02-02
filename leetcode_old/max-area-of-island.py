class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        H = len(grid)
        W = len(grid[0])
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        has_visited = set()

        def traverse(h, w):
            area = 0
            suspended = list()
            suspended.append((h, w))
            while len(suspended) != 0:
                h_, w_ = suspended.pop()
                has_visited.add((h_, w_))
                area += 1
                for (dh, dw) in dirs:
                    nh = h_ + dh
                    nw = w_ + dw
                    if 0 <= nh < H and 0 <= nw < W and (nh, nw) not in has_visited and grid[nh][nw] == 1:
                        has_visited.add((nh, nw))
                        suspended.append((nh, nw))
            return area

        max_area = 0
        for h in range(H):
            for w in range(W):
                if grid[h][w] == 1:
                    area = traverse(h, w)
                    max_area = max(max_area, area)
        return max_area
