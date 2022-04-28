# 島の形が長方形しか存在しないので行けるだけ右に行ってから行けるだけ下に行けばいい
class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        H = len(land)
        W = len(land[0])
        ans = []
        for sh in range(H):
            for sw in range(W):
                if land[sh][sw] == 0:
                    continue
                gh = sh
                while gh < H and land[gh][sw] == 1:
                    gh += 1
                if gh != 0:
                    gh -= 1
                gw = sw
                while gw < W and land[sh][gw] == 1:
                    gw += 1
                if gw != 0:
                    gw -= 1
                ans.append([sh, sw, gh, gw])
                for h in range(sh, gh + 1):
                    for w in range(sw, gw + 1):
                        land[h][w] = 0
        return ans


# BFS
class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        dirs = [(0, 1), (1, 0)]
        H = len(land)
        W = len(land[0])
        has_visited = set()
        ans = []
        for sh in range(H):
            for sw in range(W):
                if land[sh][sw] == 1 and (sh, sw) not in has_visited:
                    suspended = deque([(sh, sw)])
                    gh = sh
                    gw = sw
                    while len(suspended) != 0:
                        (h, w) = suspended.popleft()
                        has_visited.add((h, w))
                        for (dh, dw) in dirs:
                            nh = h + dh
                            nw = w + dw
                            if 0 <= nh < H and 0 <= nw < W and land[nh][nw] == 1 and (nh, nw) not in has_visited:
                                suspended.append((nh, nw))
                                if (gh, gw) < (nh, nw):
                                    (gh, gw) = (nh, nw)
                    ans.append([sh, sw, gh, gw])
        return ans

    
    # DFS
    class Solution:
        def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
            dirs = [(0, 1), (1, 0)]
            H = len(land)
            W = len(land[0])
            has_visited = set()
            ans = []
            def dfs(h, w):
                has_visited.add((h, w))
                gh = h
                gw = w
                for (dh, dw) in dirs:
                    nh = h + dh
                    nw  = w + dw
                    if not (0 <= nh < H and 0 <= nw < W):
                        continue
                    if land[nh][nw] == 0:
                        continue
                    if (gh, gw) < dfs(nh, nw):
                        (gh, gw) = dfs(nh, nw)
                return (gh, gw)
            for sh in range(H):
                for sw in range(W):
                    if land[sh][sw] == 1 and (sh, sw) not in has_visited:
                        (gh, gw) = dfs(sh, sw)
                        ans.append([sh, sw, gh, gw])
            return ans