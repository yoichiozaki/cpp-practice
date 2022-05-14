class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        G = {i: set() for i in range(1, n + 1)}
        for edge in trust:
            G[edge[0]].add(edge[1])
        nodes = [0] + [i for i in range(1, n + 1)]
        for i in range(1, n + 1):
            if len(G[i]) == 0 and all(i in G[j] for j in (nodes[1:i] + nodes[i+1:])):
                return i
        return -1