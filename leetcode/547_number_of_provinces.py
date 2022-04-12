# DFS in recursion
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        N = len(isConnected)
        G = defaultdict(list)
        for i in range(N):
            for j in range(N):
                if isConnected[i][j] == 1:
                    G[i].append(j)
                    G[j].append(i)
        has_visited = set()
        def dfs(i):
            has_visited.add(i)
            for neighbor in G[i]:
                if neighbor in has_visited:
                    continue
                dfs(neighbor)
        ans = 0
        for node in range(N):
            if node not in has_visited:
                dfs(node)
                ans += 1
        return ans


# DFS w/ stack
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        N = len(isConnected)
        G = defaultdict(list)
        for i in range(N):
            for j in range(N):
                if isConnected[i][j] == 1:
                    G[i].append(j)
                    G[j].append(i)
        has_visited = set()
        def dfs(i):
            suspended = [i]
            while len(suspended) != 0:
                node = suspended.pop()
                has_visited.add(node)
                for neighbor in G[node]:
                    if neighbor in has_visited:
                        continue
                    suspended.append(neighbor)
        ans = 0
        for node in range(N):
            if node not in has_visited:
                dfs(node)
                ans += 1
        return ans


# BFS w/ queue
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        N = len(isConnected)
        G = defaultdict(list)
        for i in range(N):
            for j in range(N):
                if isConnected[i][j] == 1:
                    G[i].append(j)
                    G[j].append(i)
        has_visited = set()
        def dfs(i):
            suspended = [i]
            while len(suspended) != 0:
                node = suspended.pop(0)
                has_visited.add(node)
                for neighbor in G[node]:
                    if neighbor in has_visited:
                        continue
                    suspended.append(neighbor)
        ans = 0
        for node in range(N):
            if node not in has_visited:
                dfs(node)
                ans += 1
        return ans


# UnionFind
class Solution:        
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        class UnionFind:
            def __init__(self, n):
                self.parents = [-1 for _ in range(n)]
            def find(self, x):
                if self.parents[x] < 0:
                    return x
                else:
                    self.parents[x] = self.find(self.parents[x])
                    return self.parents[x]
            def union(self, x, y):
                x = self.find(x)
                y = self.find(y)
                if x == y:
                    return
                if self.parents[x] > self.parents[y]:
                    x, y = y, x
                self.parents[x] += self.parents[y]
                self.parents[y] = x
            def same(self, x, y):
                return self.find(x) == self.find(y)
            def roots(self):
                return [i for i, x in enumerate(self.parents) if x < 0]
            def group_count(self):
                return len(self.roots())
        
        N = len(isConnected)
        uf = UnionFind(N)
        for i in range(N):
            for j in range(N):
                if isConnected[i][j] == 1:
                    uf.union(i, j)
        return uf.group_count()
