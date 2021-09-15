# BFSっぽく
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        G = [[] for _ in range(numCourses)]
        for prerequisity in prerequisites:
            a = prerequisity[0]
            b = prerequisity[1]
            G[b].append(a)

        indegree = [0 for _ in range(numCourses)]
        for u in range(numCourses):
            for v in G[u]:
                indegree[v] += 1

        for u in range(numCourses):
            v = 0
            while v < numCourses:
                if indegree[v] == 0:
                    break
                v += 1
            if v == numCourses:
                return False
            indegree[v] -= 1
            for adj in G[v]:
                indegree[adj] -= 1
        return True


# DFSで帰りがけ順
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        G = [[] for _ in range(numCourses)]
        for prerequisity in prerequisites:
            a = prerequisity[0]
            b = prerequisity[1]
            G[b].append(a)

        todo = [False for _ in range(numCourses)]
        done = [False for _ in range(numCourses)]

        def dfs(u):
            if todo[u]:
                return False
            if done[u]:
                return True
            todo[u] = True
            done[u] = True
            for v in G[u]:
                if not dfs(v):
                    return False
            todo[u] = False
            return True

        for u in range(numCourses):
            if not done[u] and not dfs(u):
                return False
        return True
