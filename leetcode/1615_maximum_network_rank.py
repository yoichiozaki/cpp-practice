class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        G = {i: set() for i in range(n)}
        for (city0, city1) in roads:
            G[city0].add(city1)
            G[city1].add(city0)
        ans = 0
        for i in range(n):
            for j in range(i + 1, n):
                if i in G[j]:
                    ans = max(ans, len(G[i]) + len(G[j]) - 1)
                else:
                    ans = max(ans, len(G[i]) + len(G[j]))
        return ans