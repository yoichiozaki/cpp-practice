class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        if heights is None or len(heights) == 0 or len(heights[0]) == 0:
            return heights
        
        H = len(heights)
        W = len(heights[0])
        
        reachable_from_pacific = [[False for _ in range(W)] for _ in range(H)]
        reachable_from_atlantic = [[False for _ in range(W)] for _ in range(H)]
        
        for h in range(H):
            reachable_from_pacific[h][0] = True
            reachable_from_atlantic[h][W-1] = True
        
        for w in range(W):
            reachable_from_pacific[0][w] = True
            reachable_from_atlantic[H-1][w] = True
        
        def dfs(h, w, has_visited):
            has_visited[h][w] = True
            for (dh, dw) in dirs:
                nh = h + dh
                nw = w + dw
                if not (0 <= nh < H and 0 <= nw < W):
                    continue
                if has_visited[nh][nw]:
                    continue
                if heights[nh][nw] < heights[h][w]:
                    continue
                dfs(nh, nw, has_visited)
            
        for h in range(H):
            dfs(h, 0, reachable_from_pacific)
            dfs(h, W-1, reachable_from_atlantic)
        
        for w in range(W):
            dfs(0, w, reachable_from_pacific)
            dfs(H-1, w, reachable_from_atlantic)
        
        ret = []
        for h in range(H):
            for w in range(W):
                if reachable_from_pacific[h][w] and reachable_from_atlantic[h][w]:
                    ret.append([h, w])
        return ret
            