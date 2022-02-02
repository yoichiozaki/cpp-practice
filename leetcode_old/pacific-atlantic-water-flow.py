# BFS from Ocean w/ queue
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        if heights is None or len(heights) == 0 or len(heights[0]) == 0:
            return heights

        H = len(heights)
        W = len(heights[0])

        reachable_from_pacific = [[False for _ in range(W)] for _ in range(H)]
        reachable_from_atlantic = [[False for _ in range(W)] for _ in range(H)]

        pacific_queue = collections.deque([])
        altantic_queue = collections.deque([])

        for h in range(H):
            pacific_queue.append((h, 0))
            altantic_queue.append((h, W-1))
            reachable_from_pacific[h][0] = True
            reachable_from_atlantic[h][W-1] = True

        for w in range(W):
            pacific_queue.append((0, w))
            altantic_queue.append((H-1, w))
            reachable_from_pacific[0][w] = True
            reachable_from_atlantic[H-1][w] = True

        while len(pacific_queue) != 0:
            h, w = pacific_queue.popleft()
            for (dh, dw) in dirs:
                nh = h + dh
                nw = w + dw
                if nh < 0 or H <= nh or nw < 0 or W <= nw or reachable_from_pacific[nh][nw] or heights[nh][nw] < heights[h][w]:
                    continue
                reachable_from_pacific[nh][nw] = True
                pacific_queue.append((nh, nw))

        while len(altantic_queue) != 0:
            h, w = altantic_queue.popleft()
            for (dh, dw) in dirs:
                nh = h + dh
                nw = w + dw
                if nh < 0 or H <= nh or nw < 0 or W <= nw or reachable_from_atlantic[nh][nw] or heights[nh][nw] < heights[h][w]:
                    continue
                reachable_from_atlantic[nh][nw] = True
                altantic_queue.append((nh, nw))

        ret = []
        for h in range(H):
            for w in range(W):
                if reachable_from_pacific[h][w] and reachable_from_atlantic[h][w]:
                    ret.append([h, w])
        return ret


# DFS from Ocean w/ stack
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        if heights is None or len(heights) == 0 or len(heights[0]) == 0:
            return heights

        H = len(heights)
        W = len(heights[0])

        reachable_from_pacific = [[False for _ in range(W)] for _ in range(H)]
        reachable_from_atlantic = [[False for _ in range(W)] for _ in range(H)]

        pacific_stack = []
        altantic_stack = []

        for h in range(H):
            pacific_stack.append((h, 0))
            altantic_stack.append((h, W-1))
            reachable_from_pacific[h][0] = True
            reachable_from_atlantic[h][W-1] = True

        for w in range(W):
            pacific_stack.append((0, w))
            altantic_stack.append((H-1, w))
            reachable_from_pacific[0][w] = True
            reachable_from_atlantic[H-1][w] = True

        while len(pacific_stack) != 0:
            h, w = pacific_stack.pop()
            for (dh, dw) in dirs:
                nh = h + dh
                nw = w + dw
                if nh < 0 or H <= nh or nw < 0 or W <= nw or reachable_from_pacific[nh][nw] or heights[nh][nw] < heights[h][w]:
                    continue
                reachable_from_pacific[nh][nw] = True
                pacific_stack.append((nh, nw))

        while len(altantic_stack) != 0:
            h, w = altantic_stack.pop()
            for (dh, dw) in dirs:
                nh = h + dh
                nw = w + dw
                if nh < 0 or H <= nh or nw < 0 or W <= nw or reachable_from_atlantic[nh][nw] or heights[nh][nw] < heights[h][w]:
                    continue
                reachable_from_atlantic[nh][nw] = True
                altantic_stack.append((nh, nw))

        ret = []
        for h in range(H):
            for w in range(W):
                if reachable_from_pacific[h][w] and reachable_from_atlantic[h][w]:
                    ret.append([h, w])
        return ret


# DFS from Ocean in recursion
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
                if nh < 0 or H <= nh or nw < 0 or W <= nw or has_visited[nh][nw] or heights[nh][nw] < heights[h][w]:
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
