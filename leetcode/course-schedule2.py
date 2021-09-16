# DFSの帰りがけ順
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        G = [[] for _ in range(numCourses)]
        for prereq in prerequisites:
            a = prereq[0]
            b = prereq[1]
            G[b].append(a)
        has_visited = set()
        finished = set()
        ret = []

        def dfs(node):
            has_visited.add(node)
            for u in G[node]:
                if u in finished:
                    continue
                if u in has_visited and u not in finished:
                    return
                dfs(u)
            finished.add(node)
            ret.append(node)
        for i in range(numCourses):
            if i in has_visited:
                continue
            dfs(i)
        ret.reverse()
        return ret


# BFSっぽく入次数に注目
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        G = [[] for _ in range(numCourses)]
        for prereq in prerequisites:
            a = prereq[0]
            b = prereq[1]
            G[b].append(a)
        indegree = [0 for _ in range(numCourses)]
        for u in range(numCourses):
            for v in G[u]:
                indegree[v] += 1
        que = []
        for u in range(numCourses):
            if indegree[u] == 0:
                que.append(u)
        ret = []
        while len(que) != 0:
            u = que.pop(0)
            for v in G[u]:
                indegree[v] -= 1
                if indegree[v] == 0:
                    que.append(v)
            ret.append(u)
        return ret if len(ret) == numCourses else []
